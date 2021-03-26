#include "List.h"

int List::count()
{
    int counter = 0;
    // iterator is a pointer that can move through a list, pointing at a node at a time
    Node* iterator = head;
    //Loop until we are pointing at nothing (the end of the list)
    while (iterator != NULL)
    {
        iterator = iterator->next;// the end of the list, next == NULL
        counter++;
    }

    return counter;
}

void List::displayList()
{
    Node* iterator = head;
    while (iterator != NULL)
    {
        //(*iterator).name    dereference pointer and access public
        cout << iterator->num << endl;
        iterator = iterator->next;
    }
}

void List::insertAtFront(int num)
{
    Node* newNode = new Node(num);

    //make new nodes next point to current head
    newNode->next = head;
    //update who is front of list
    head = newNode;
}

void List::insertAtEnd(int num)
{
    // if list is empty, use insert at front logic 
    if (head == NULL)
    {
        insertAtFront(num);
        return; //exit function early so the rest doesn't happen as well.
    }

    Node* newNode = new Node(num);

    // setup iterator and move it to the final thing in the list
    Node* iterator = head;
    while (iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    //now we are pointing at the last position
    //so attach newNode to it
    iterator->next = newNode;
}

void List::insertAtPosition(int num, int index)
{
    // if list is empty, use insert at front logic 
    if (head == NULL)
    {
        insertAtFront(num);
        return; //exit function early so the rest doesn't happen as well.
    }
    // if index requested for insert exceeds size of list or same size
    // then insert at the end
    if (index >= count())
    {
        insertAtEnd(num);
        return;
    }

    Node* newNode = new Node(num);

    //move 2 iterators up to index node and the previous one to that
    Node* iterator = head;
    Node* previous = head;
    for (int i = 0; i < index; i++)
    {
        previous = iterator;
        iterator = iterator->next;
    }
    //fit new node into the list
    previous->next = newNode;
    newNode->next = iterator;
    
}

void List::deleteAtFront()
{
    //if list is empty, nothing to delete
    if (head == NULL)
        return;

    Node* iterator = head; //remember heads position
    //move head up to the next position
    head = head->next;
    //delete old head
    delete iterator;
}

void List::deleteAtEnd()
{
    //if list is empty, nothing to delete
    if (head == NULL)
        return;

    // get pointers to point at last node for deletion
    // and second last to detatch last one safely
    Node* iterator = head;
    Node* previous = head;
    while (iterator->next != NULL)
    {
        previous = iterator;
        iterator = iterator->next;
    }
    //detach back (doesn't delete it)
    previous->next = NULL;
    //delete last node in my list
    delete iterator;
}

void List::deleteAtPosition(int index)
{
    //if list is empty, nothing to delete
    if (head == NULL)
        return;
    //if the index is at front 
    if (index == 0)
    {
        deleteAtFront();
        return;
    }
    //if index is last node or greater than 
    if (index >= count() - 1)
    {
        deleteAtEnd();
        return;
    }

    //move 2 iterators up to index node and the previous one to that
    Node* iterator = head;
    Node* previous = head;
    for (int i = 0; i < index; i++)
    {
        previous = iterator;
        iterator = iterator->next;
    }
    //detach index node, by rerouting the previous nodes next pointer 
    //to the node after the one we want to delete
    previous->next = iterator->next;
    // safe to delete node now
    delete iterator;
}
