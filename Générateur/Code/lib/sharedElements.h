#ifndef SHAREDELEMENTS_H
#define SHAREDELEMENTS_H

#define _CRT_SECURE_NO_WARNINGS

#define FFLUSH()              \
    while (getchar() != '\n') \
    {                         \
    }

//Does should be dynamic instead
#define BUFFER_SIZE 2048
#define DEFNAME_SIZE 64
#define BALISENAME_SIZE 256
#define TEXT_SIZE 1024

#define APOSTROPHE_ASCII 39

//Should have a class for handeling errors
#define SUCCES 0
#define ERROR_DEFNAME 1
#define	ERROR_BALISENAME 2
#define ERROR_TEXT 3
#define ERROR_ROWBLANK 10
#define ERROR_READ_NO_MODE 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

//This is not a feature release, to be removed
void toClipboard(const char* s);

#endif // !SHAREDELEMENTS_H