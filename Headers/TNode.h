#pragma once
#include <iostream>

template <class T>
struct TNode{
	T value;
	TNode* pNext;

	TNode(const T& val = T(), TNode* next = NULL) : value(val), pNext(next) {}
};

