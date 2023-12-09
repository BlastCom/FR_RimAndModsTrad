#include "sharedElements.h"

void toClipboard(const char* s)
{
	OpenClipboard(0);
	EmptyClipboard();
	/*
	const char* test = "Test clipboard";
	const size_t testLen = strlen(test) + 1;
	*/
	const size_t s_len = strlen(s) + 1;
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s_len);
	if (!hg) {
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), s, s_len);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}
