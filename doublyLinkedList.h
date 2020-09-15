#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;


// node

struct node
{
    int data;
    node *next;
    node *prev;
};







// doubly linked list
class DoublyLinkedList
{
    private:

        node *head;
        node *prev;

    public:

        DoublyLinkedList()
        {
            head = NULL;
            prev = NULL;
        }


        node* generateHead(int data)
        {
            // making a new node
            node *tmp = new node;

            // adding data
            tmp->data = data;
            tmp->next = NULL;
            tmp->prev = NULL;

            // making the new node as head
            head = tmp;

            return head;
        }
};



// function to add to the beginning of the doubly linked list
void addToBeginning_doublyLinkedList(node* &head , int data)
{
    // new node
    node* newNode = new node();

    // tmp node which has contents of head
    node* tmp = head;

    // new node init
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    // head prev will point to new node
    tmp->prev = newNode;
    
    // new node will become head
    head = newNode;
}


// function to display elements
// pass the head of the linked list
// things will be seperated by the string seperator
void displayFromHead_doublyLinkedList(node* head , string seperator = " ")
{
    // new node points to head of linked list
    node *tmp;
    tmp = head;

    // if the list as no further node
    while (tmp != NULL)
    {
        cout << tmp->data <<seperator;

        // making the node to node pointed by tmp next
        tmp = tmp->next;
    }
}



// function to display elements
// pass the tail of the linked list
// things will be seperated by the string seperator
void displayFromTail_doublyLinkedList(node* tail , string seperator = " ")
{
    // new node points to head of linked list
    node *tmp;
    tmp = tail;

    // if the list as no further node
    while (tmp != NULL)
    {
        cout << tmp->data <<seperator;

        // making the node to node pointed by tmp next
        tmp = tmp->prev;
    }
}


// function to find the size of linked list 
// keep one NULL and pass the value of other
int size_doublyLinkedList(node* head = NULL , node* tail = NULL)
{

    // new node points to head of linked list
    node *tmp;
    int size = 0; 

    // if the tail is provided
    if(head == NULL)
    {

        tmp = tail;
        while (tmp != NULL)
        {
            size++;

            // making the node to node pointed by tmp next
            tmp = tmp->prev;
        }
    }
    

    // if the head is provided
    if(tail == NULL)
    {

        tmp = head;
    // if the list as no further node
    while (tmp != NULL)
    {
        size++;

        // making the node to node pointed by tmp next
        tmp = tmp->next;
    }

    
    }

    return size;
}



#endif