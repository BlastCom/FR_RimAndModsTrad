#include "sharedElements.h"

#define INPUT_FILE_NAME "TranslationReport.txt"

#define SIZE_SECTION_NAME 256

#define SECTION_MISSING_KEYED "Missing keyed translations"
#define SECTION_MISSING_KEYED "Def-injected translations missing"

int dynamicProcessMain(void);
int readRepport(FILE* readFile, char* defName, char* baliseName, char* text, int mode);