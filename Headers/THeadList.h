#pragma once
#include "TList.h"

using namespace std;

template <class T>
class THeadList :
    public TList<T>
{
protected:
    TNode<T>* pHead;

public:
    THeadList() {
        pHead = new TNode<T>();
        pHead->pNext = pHead;
        pStop = pHead;
        pLast = pFirst = pHead;
        pCurr = pPrev = pHead;
        len = 0;
    }

    ~THeadList() {
        /*pCurr = pFirst;
        while (pCurr != pStop) {
            pPrev = pCurr;
            pCurr = pCurr->pNext;
            delete pPrev;
        }
        delete pHead;*/

        while (pFirst != pStop) {
            TNode<T>* node = pFirst;
            pFirst = pFirst->pNext;
            delete node;
        }
        delete pHead;
    }

    void InsFirst(const T& val) {
        TList::InsFirst(val);
        pHead->pNext = pFirst;
    }

    void DelFirst() {
        TList::DelFirst();
        pHead->pNext = pFirst;
    }
};

