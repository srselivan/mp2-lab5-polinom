#pragma once
#include "TNode.h"

template <class T>
class TList {
protected:
	TNode<T>* pFirst, * pLast, * pStop, * pCurr, * pPrev;
	int len;

public:
	TList() :pFirst(NULL), len(0), pLast(NULL), pStop(NULL), pCurr(NULL), pPrev(NULL) {}

	TList(const TList& theList) : TList() {
		
	}

	void InsFirst(T _value) {
		TNode<T>* p = new TNode<T>(_value, pFirst);
		pFirst = p;
		len++;
		if (len == 1) { pLast = pFirst; }
	}

	void InsLast(T _value) {
		TNode<T>* p = new TNode<T>(_value, pStop);
		if (pLast == pStop) { pFirst = p; }
		else { pLast->pNext = p; }
		pLast = p;
		len++;
	}

	void InsCurr(T _value) {
		if (pCurr == pFirst) {
			InsFirst(_value);
		}
		else if (pPrev == pLast) {
			InsLast(_value);
		}
		else {
			TNode<T>* p = new TNode<T>(_value, pCurr);
			pPrev->pNext = p;
			pCurr = p;
			len++;
		}
	}

	void DelCurr() {
		if (pCurr != pStop) {
			if (pCurr == pFirst)
				DelFirst();
			else
			{
				TNode<T>* del = pCurr;
				pCurr = pCurr->pNext;
				pPrev->pNext = pCurr;
				delete del;
				len--;
			}
		}
	}

	void DelFirst() {
		if (pFirst != pStop) {
			TNode<T>* del = pFirst;
			pFirst = pFirst->pNext;
			delete del;
			len--;
			if (len == 0) { pLast = pStop; }
		}
	}

	T GetCurrVal() {
		if (pCurr != pStop) return pCurr->value;
		throw "ERROR";
	}

	bool IsEmpty() {
		return len == 0;
	}

	void Reset() {
		pCurr = pFirst;
		pPrev = pStop;
	}

	void GoNext() {
		pPrev = pCurr;
		pCurr = pCurr->pNext;
	}

	bool IsEnd() const { 
		return pCurr == pStop; 
	}

};

