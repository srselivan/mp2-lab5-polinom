#pragma once
#include "THeadList.h"

class TPolinom :
    public THeadList<TMonom>
{
public:
    TPolinom() {
        TMonom m(0, 0, -1);
        pHead->value = m;
    }

    TPolinom(TPolinom& p){
        for (p.Reset(); !(p.IsEnd()); p.GoNext()){
            InsLast(p.pCurr->value);
        }
    }

    void AddMonom(const TMonom m) {
        if (pLast->value > m) {
            InsLast(m);
            return;
        }
        for (Reset(); !IsEnd(); GoNext()) {
            if (pCurr->value == m) {
                pCurr->value.coef += m.coef;
                if (pCurr->value.coef == 0) {
                    DelCurr();
                }
                break;
            }
            if (pCurr->value < m) {
                InsCurr(m);
                break;
            }
        }
    }

    TPolinom operator+ (TPolinom& p) {
		TPolinom result = *this;
		p.Reset();
		result.Reset();
		while (!p.IsEnd()) {
			if (result.pCurr->value > p.pCurr->value){
				result.GoNext();
			}
			else if (result.pCurr->value < p.pCurr->value) {
				result.InsCurr(p.pCurr->value);
				p.GoNext();
			}
			else {
				result.pCurr->value.coef += p.pCurr->value.coef;
				if (result.pCurr->value.coef != 0) {
					result.GoNext();
                    p.GoNext();
				} else {
					result.DelCurr();
                    p.GoNext();
				}
			}
		}
		return result;
    }
};

