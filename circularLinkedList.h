#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;


// node
struct node
{
    int data;
    node *next;
};









// circular linked list
class CircularLinkedList
{
    private:

        node *head;

    public:

        CircularLinkedList()
        {
            head = NULL;
        }


        node* generateHead(int data)
        {
            // making a new node
            node *tmp = new node;

            // adding data
            tmp->data = data;
            // this new node will point to itself
            tmp->next = tmp;

            // making the new node as head
            head = tmp;

            return head;
        }
};


// function to traverse a circular linked list 
void display_CircularLinkedList(node* head , string seperator = " ")
{
    // new node points to head of linked list
    node *tmp;
    tmp = head;

    // should run only if linked list is not NULL
    if(tmp != NULL)
    {
    // loop will execute at least ones
    do 
    {
        cout << tmp->data <<seperator;
        tmp = tmp->next;

    } while((tmp != head));
    }

    return;
}


// function to return last node of a circular linked list 
node* returnLastNode_circularLinkedList(node* head)
{
    // new node points to head of linked list
    node *tmp , *prev;
    tmp = head;

    // should run only if linked list is not NULL
    if(tmp != NULL)
    {
    // loop will execute at least ones
    do 
    {
        prev = tmp;
        tmp = tmp->next;
    } while((tmp != head));
    }

    return prev;
}


// function to add a node to a empty circular list
void addToEmpty_circularLinkedList(node* &head , int data)
{
    CircularLinkedList cl;
    head = cl.generateHead(data);
}



// function to add at the beginning of the circular linked list
void addTobeginning_circularLinkedList(node* &head , int data)
{
    // if the list is empty
    if(head == NULL)
    {
        addToEmpty_circularLinkedList(head , data);
        return;
    }

    // making new node
    node* newNode = new node();  

    newNode->data = data; 
    // newNode will point to the head 
    newNode->next = head;

    // getting the last of the circular linked list 
    node* last = returnLastNode_circularLinkedList(head);

    // making the last to point to the new node
    last->next = newNode;
    head = newNode;
}



// function to add after a certain position in circular linked list
// position starts from one
// if you pass 2 as pos to add 10 on a linked list which is 1 -> 2 -> 3 then it will become 1 -> 10 -> 2 -> 3
// it will add on that position not after that position
// throws const char * error if the position is out of scope
void addToAfterPos_circularLinkedList(node* &head , int pos , int data)
{

    // as we have to add on that position and after that position
    pos = pos - 1;

    // if the list is empty
    if(head == NULL)
    {
        addToEmpty_circularLinkedList(head , data);
        return;
    }

    // if pos = 0 then we have to add to beginning 
    if(pos == 0)
    {
        addTobeginning_circularLinkedList(head , data);
        return;
    }


    // new node points to head of linked list
    node *tmp , *prev;
    tmp = head;

    int count = 1;

    // should run only if linked list is not NULL
    if(tmp != NULL)
    {
    // loop will execute at least ones
    do 
    {
        // keeping track of the previous node
        prev = tmp;

        // if the count reaches pos
        if(count == pos)
        {
            // making new node
            node* newNode = new node();  

            newNode->data = data; 
            // new node will point to the next element in list 
            newNode->next = tmp->next;
            // prev node will point to new node
            prev->next = newNode;
            return;
        }
        tmp = tmp->next;
        count++;
    } while((tmp != head));
    }

    cout<<count;

    throw "position not found";
}



// function to add a node at the end of circular linked list
void addToEnd_circularLinkedList(node* &head , int data)
{
    // this is only for empty list 
    if(head == NULL)
    {
        addToEmpty_circularLinkedList(head , data);
        return;
    }

    // getting the last node
    node* last = returnLastNode_circularLinkedList(head);
    
    // making new node 
    node* newNode = new node();  

    newNode->data = data; 
    // new node will point to head  
    newNode->next = head;
    // last node will point to new node
    last->next = newNode;
}


#endif