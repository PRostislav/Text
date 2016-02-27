#pragma once
#include <string.h>
const int MaxLen = 100;

class TLink {
	//----
	public:
		char String[MaxLen];
		TLink* pSame, *pDown;
		//----
		TLink(char* _String = NULL, TLink* _pSame = NULL, TLink* _pDown=NULL) {
			pSame = _pSame;
			pDown = _pDown;
			strcpy_s(String, _String); //copy _String to the String
		}
		~TLink(); //Nothing is dynamic - empty destructor
};

