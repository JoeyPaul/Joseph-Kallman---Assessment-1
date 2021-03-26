#include "Node.h"

Node::Node()
{
	next = NULL; //  just to make sure it's not being used for anything, set it to null first
}

Node::Node(int num)
{
	next = NULL;

	this->num = num;
}