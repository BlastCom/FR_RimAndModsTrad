#include "dynamicProcess.h"

//This doen't seems to do anything
int dynamicProcessMain(void)
{
	FILE* readFile;
	FILE* writeFile;

	//Open the translation report
	fopen_s(&readFile, INPUT_FILE_NAME, "r");

	//An error happend, maybe no translation report
	if (readFile == NULL)
	{
		printf("ERROR READ; PROGRAM STOPED\n");
		return 0;
	}

	while (!feof(readFile)) //Loop until end of file
	{
		char mainBuffer[BUFFER_SIZE];
		char section[SIZE_SECTION_NAME];
		
		//Gérer la détection de la section

		rewind(readFile); //Goes back to start of file
		fgets(mainBuffer, BUFFER_SIZE, readFile); //Get single string in file
		strstr(mainBuffer, section); //finds "section" inside of "mainBuffer"
	}

	return 0;
}

int readRepport(FILE* readFile, char* defName, char* baliseName, char* text, int mode)
{
	char buffer[BUFFER_SIZE];
	char* strBuffer;
	char* ptrLastApostrophe;

	int i;
	int step_val = 0;
	int index;

	// Set all elements to 0 -> initializing
	memset(buffer, 0, sizeof(buffer));
	memset(defName, 0, sizeof(defName));
	memset(baliseName, 0, sizeof(baliseName));
	memset(text, 0, sizeof(text));

	// Get first string in file given
	fgets(buffer, BUFFER_SIZE, readFile);
	strBuffer = buffer;

	// Needs review, probably some indent file reading
	switch (mode)
	{
	case 1:				//Missing Keyed
		step_val = 1;	//Skip une étape de lecture
		strcpy(defName, "Keyed");
		break;
	case 2:				//Missing Defs-Injected
		step_val = 0;
		break;
	default:
		return ERROR_READ_NO_MODE;
		break;
	}

	// Needs review
	for (i = step_val; i < 2; i++)
	{
		index = 0;
		do
		{
			while (strBuffer[0] == '\t' || strBuffer[0] == ' ' || strBuffer[0] == '\n' || strBuffer[0] == 0)
			{
				strBuffer++;
				if (strBuffer[0] == '\0')
				{
					return ERROR_ROWBLANK;
				}
			}
			if (i == 0)
				defName[index++] = strBuffer[0];	//!
			else if (i == 1)
				baliseName[index++] = strBuffer[0];
			strBuffer++;

			if (i == 0 && index >= DEFNAME_SIZE)
				return ERROR_DEFNAME;
			else if (i == 1 && index >= BALISENAME_SIZE)
				return ERROR_BALISENAME;

		} while (strBuffer[0] != ' ');
		strBuffer++;

		if (i == 0) //!
			defName[--index] = '\0';
		else if (i == 1)
			baliseName[index] = '\0';
	}

	strBuffer++;
	index = 0;
	ptrLastApostrophe = strrchr(strBuffer, APOSTROPHE_ASCII);
	do
	{
		text[index++] = strBuffer[0];
		strBuffer++;
		if (index >= TEXT_SIZE)
			return ERROR_TEXT;

	} while (ptrLastApostrophe != strBuffer);
	text[index] = '\0';

	return SUCCES;
}