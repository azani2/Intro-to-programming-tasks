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

template<typename T>
int getLength(Node<T>* list) {
	int length = 0;
	while (list) {
		length++;
		list = list->next;
	}
	return length;
}

template<typename T>
Node<T>* getNodeAt(Node<T>* list, int idx) {
	if (!list) throw std::invalid_argument("Invalid operation.");
	int length = getLength(list);
	if (idx >= length || idx < 0) throw std::invalid_argument("Index out of bounds.");

	for (int i = 0; i < idx; i++)
		list = list->next;
	return list;
}

template<typename T>
Node<T>* reverseSublist(Node<T>* list, int from, int to) {
	if (!list) return nullptr;
	int length = getLength(list);
	if (from > length || to > length || from < 0 || to < 0 || from > to) {
		throw std::invalid_argument("Index out of bounds.");
	}

	Node<T>* result = nullptr;
	Node<T>* reversed = nullptr;
	Node<T>* startReverse = getNodeAt(list, from);
	Node<T>* lastReverse = getNodeAt(list, to);

	while (list != startReverse) {
		pushBack(list->value, result);
		list = list->next;
	}

	while (startReverse != lastReverse) {
		pushFront(startReverse->value, reversed);
		startReverse = startReverse->next;
		list = list->next;
	}
	pushFront(lastReverse->value, reversed);
	
	while (reversed) {
		pushBack(reversed->value, result);
		reversed = reversed->next;
	}

	list = list->next;
	while (list) {
		pushBack(list->value, result);
		list = list->next;
	}
	
	clear(reversed);
	return result;
}

template<typename T>
Node<T>* reverseSublists(Node<T>* list, Node<std::pair<int, int>>* intervals) {
	while (intervals) {
		int from = intervals->value.first;
		int to = intervals->value.second;
		list = reverseSublist(list, from, to);
		print(list);
		std::cout << std::endl;
		intervals = intervals->next;
	}
	return list;
}

/*
int main() {
	Node<int>* testList = nullptr;
	for (int i = 1; i < 11; i++)
		pushBack(i, testList);

	Node<std::pair<int, int>>* intervals = nullptr;
	pushBack(std::pair<int, int>(1, 3), intervals);
	pushBack(std::pair<int, int>(3, 6), intervals);
	pushBack(std::pair<int, int>(7, 8), intervals);
	pushBack(std::pair<int, int>(5, 9), intervals);

	reverseSublists(testList, intervals);

	clear(testList);
	clear(intervals);
}
*/
