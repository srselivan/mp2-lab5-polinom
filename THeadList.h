#pragma once
#include "TList.h"
#include "TMonom.h"

template <class T>
class THeadList :
    public TList<TMonom>
{
protected:
    TNode<T>* pHead;

public:
    THeadList() {
        pHead = new TNode<T>;
        pHead->pNext = pHead;
        pStop = pHead;
        pLast = pFirst = pHead;
        pCurr = pPrev = pHead;
        len = 0;
    }

    ~THeadList() {
        pCurr = pFirst;
        while (pCurr != pStop) {
            pPrev = pCurr;
            pCurr = pCurr->pNext;
            delete pPrev;
        }
        delete pHead;
    }

    void InsFirst(T val) {
        TList::InsFirst(val);
        pHead->pNext = pFirst;
    }

    void DelFirst() {
        TList::DelFirst();
        pHead->pNext = pFirst;
    }
};

