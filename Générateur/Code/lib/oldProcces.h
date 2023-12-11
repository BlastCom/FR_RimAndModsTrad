/**
 * @file oldProcces.h
 * @author Simon Laflamme
 * @brief  Looks like to be old draft code, some code review is needed
 * @version 0.1
 * @date 2021-??-??
 * 
 * @copyright Copyright (c) 2023
 * 
 */

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