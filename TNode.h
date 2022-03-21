#pragma once
#include <iostream>

template <class T>
class TNode{
public:
	T value;
	TNode* pNext;

	TNode(const T& val, TNode* next = NULL) : value(val), pNext(next) {}
};

