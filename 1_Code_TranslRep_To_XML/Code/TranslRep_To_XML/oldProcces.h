#ifndef OLDPROCESS_H
#define OLDPROCESS_H

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

#define LOWERCASE_OFFSET 'a' - 'A'

#include "sharedElements.h"

int readRepport(FILE* readFile, char* defName, char* baliseName, char* text, int mode);
int writeXML(FILE* writeFile, char* defName, char* baliseName, char* text);
int oldProccesMain(void);

#endif