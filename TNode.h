#pragma once
template <class T>
class TNode{
	T value;
	TNode* pNext;

	TNode(const T& val, TNode* next = NULL) : value(val), pNext(next) {}
};

