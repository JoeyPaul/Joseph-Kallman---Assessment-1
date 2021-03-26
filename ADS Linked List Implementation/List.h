#pragma once
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;
class List
{
public:
	// points to front of our linked list
	Node* head = NULL;

	int count();
	void displayList();

	void insertAtFront(int num);
	void insertAtEnd(int num);
	void insertAtPosition(int num, int index);

	void deleteAtFront();
	void deleteAtEnd();
	void deleteAtPosition(int index);
};

