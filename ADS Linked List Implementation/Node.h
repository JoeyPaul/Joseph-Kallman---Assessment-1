#pragma once
#include <iostream>
#include <string>

using namespace std;
class Node
{
public:
	//data
	int num;

	//pointer to next node
	Node* next;

	// constructors   ( fucntion that gets called automatically at the creation of the class)
	Node();
	Node(int num);  // if you have two functions of the same name but different parameters its called function overloading

};

