#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
struct Node {
	T value;
	Node<T>* next;
};

template<typename T>
Node<T>* create(const T& value, Node<T>* next = nullptr) {
	return new Node<T>{ value, next };
}

template<typename T>
void pushFront(const T& value, Node<T>*& list) {
	list = create(value, list);
}

template<typename T>
void pushBack(const T& value, Node<T>*& list) {
	if (!list) {
		list = create(value);
		return;
	}
	Node<T>* iter = list;
	while (iter->next) iter = iter->next;
	iter->next = create(value);
}

template<typename T>
void popFront(Node<T>*& list) {
	if (!list) return;

	Node<T>* toDelete = list;
	list = list->next;
	delete toDelete;
}

template<typename T>
void deleteAfter(Node<T>*& node) {
	Node<T>* toDelete = node->next;
	if (!toDelete) return;

	node->next = toDelete->next;
	delete toDelete;
}


template<typename T>
void clear(Node<T>*& list) {
	while (list) {
		popFront(list);
	}
}


template<typename T>
void print(Node<T>* list) {
	while (list) {
		std::cout << list->value << " ";
		list = list->next;
	}
}

void removeBalancedElements(Node<int>*& list) {
	Node<int>* prev = list;
	Node<int>* iter = list->next;
	while (iter && iter->next) {
		Node<int>* next = iter->next;
		bool elementIsBalanced = (prev->value + next->value == iter->value);
		if (elementIsBalanced) {
			iter = iter->next;
			deleteAfter(prev);
			continue;
		}
		prev = iter;
		iter = iter->next;
	}
}

bool isBalanced(Node<int>*& list) {
	if (!list) return true;
	bool balanced = true;
	Node<int>* prev = list;
	Node<int>* iter = list->next;
	while (iter && iter->next) {
		Node<int>* next = iter->next;
		balanced &= (prev->value + next->value == iter->value);
		prev = iter;
		iter = iter->next;
	}

	if (balanced) return true;
	removeBalancedElements(list);
	return false;
}
/*
int main() {
	Node<int>* testList1 = nullptr;
	pushBack(1, testList1);
	pushBack(-4, testList1);
	pushBack(-5, testList1);
	pushBack(-1, testList1);
	pushBack(4, testList1);

	print(testList1);
	std::cout << (isBalanced(testList1) ? " -> balanced\n" : " -> not balanced\n");

	Node<int>* testList2 = nullptr;
	pushBack(10, testList2);
	pushBack(5, testList2);
	pushBack(-5, testList2);
	pushBack(-15, testList2);
	pushBack(2, testList2);

	print(testList2);
	std::cout << (isBalanced(testList2) ? " -> balanced\n" : " -> not balanced\n");
	print(testList2);
}
*/