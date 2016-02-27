#pragma once
#include "TLink.h"
#include "TStack.h"


class TText {
	TLink *pFirst, *pCurrent;
	TStack<TLink*> Path; //needed to remember the way back
	//----
	public:
		TText(TLink* _Pointer) :Path(100) {
			if (_Pointer != NULL) {
				pFirst = _Pointer;
				pCurrent = NULL;
			}
		}

		~TText(); //Nothing is dynamic - empty destructor
		//----
		//Navigation:
		void GoSame() {
			if (pCurrent != NULL) {
				if (pCurrent->pSame != NULL) {
					Path.Push(pCurrent);
					pCurrent = pCurrent->pSame;
				}
			}
			else
				throw - 1;
		}

		void GoDown() {
			if (pCurrent != NULL) {
				if (pCurrent->pDown != NULL) {
					Path.Push(pCurrent);
					pCurrent = pCurrent->pDown;
				}
			}
			else
				throw - 1;

		}

		void GoPrev() {
			if (!Path.IsEmpty()) {
				pCurrent = Path.Pop();
			}
		}

		void GoFirst() {
			while (!Path.IsEmpty()) {
				Path.Pop();
			}
			pCurrent = pFirst;
		}
		//----
		//Modification:
		void AddSameLine(char *_String = NULL) {
			if (pCurrent != NULL) {
				TLink *tmp = new TLink(_String);
				tmp->pSame = pCurrent->pSame;
				pCurrent->pSame = tmp;
			}
			else
				throw - 1;

		}

		void AddDownLine(char *_String = NULL) {
			if (pCurrent != NULL) {
				TLink *tmp = new TLink(_String);
				tmp->pSame = pCurrent->pDown;
				pCurrent->pDown = tmp;
			}
			else
				throw - 1;

		}

		void AddSameSection(char *_String = NULL) {
			if (pCurrent != NULL) {
				TLink *tmp = new TLink(_String);
				tmp->pDown = pCurrent->pSame;
				pCurrent->pSame = tmp;
			}
			else
				throw - 1;

		}

		void AddDownSection(char *_String = NULL) {
			if (pCurrent != NULL) {
				TLink *tmp = new TLink(_String);
				tmp->pDown = pCurrent->pDown;
				pCurrent->pDown = tmp;
			}
			else
				throw - 1;

		}

		void DelSame() {
			if (pCurrent != NULL) {
				TLink* tmp = pCurrent->pSame->pSame;
				delete pCurrent->pSame;
				pCurrent->pSame = tmp;
			}
			else
				throw - 1;

		}
		
		void DelDown() {
			if (pCurrent != NULL) {
				TLink* tmp = pCurrent->pDown->pSame;
				delete pCurrent->pDown;
				pCurrent->pDown = tmp;
			}
			else
				throw - 1;

		}
		//----
		//Search:
		void Reset() {
			pCurrent = pFirst;
			Path.Clear();
			if (pCurrent->pSame != NULL) {
				Path.Push(pCurrent->pSame);
				Path.Push(pCurrent->pDown);
			}
		}

		void Go() {
			if (!Path.IsEmpty()) {
				pCurrent = Path.Pop();
				if (pCurrent->pSame != NULL) {
					Path.Push(pCurrent->pSame);
					Path.Push(pCurrent->pDown);
				}
			}
		}

		bool IsEnd() {
			return (Path.IsEmpty());
		}
};

