#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>

using namespace std;


// node
struct node
{
    int data;
    node *next;
};


// singlylinkedlist operations
class SinglyLinkedList
{
    private:

        node *head,*tail;

    public:

        SinglyLinkedList()
        {
            head = NULL;
            tail = NULL;
        }

        // function for adding a node
        void addNode(int data)
        {
            // temp node
            node *tmp = new node;
            tmp->data = data;
            tmp->next = NULL;

            // if linked list is empty
            if(head == NULL)
            {
                head = tmp;
                tail = tmp;
            }

            else
            {
                // tail pointer points to tmp node
                tail->next = tmp;

                // now tail is tmp node
                tail = tail->next;
            }
        } 

        node* returnHead()
        {
            return head;
        }
};


// returns the pointer to a certain position in a linked list
// position is like index + 1 
node* returnPointerToPos(node* head , int pos)
{
    // new node points to head of linked list
    node *tmp;
    tmp = head;


    // if the list as no further node
    while (tmp != NULL)
    {
        if(pos == 1)
        {
            return tmp;
        }
        pos--;
        tmp = tmp->next;
    }

    return NULL;
}


// function for pushing the element at the top of linked list
// pass the head of the linked list
void push_SinglyLinkedList(node* &head_ref, int new_data)  
{  
    // new temp node
    node* newNode = new node();  

    newNode->data = new_data;  
    newNode->next = head_ref;

    // now the head is the new node  
    head_ref = newNode;
}  


// function for insert a element after a certain node
// pass the prevNode value
// you can get the previous node pointer using returnPointerToPos() function 
void insertAfterCertainNode_SinglyLinkedList(node* prevNode, int new_data) 
{ 
    // throw error if the previous node is null as if previous node will be null then it should be last node
    if (prevNode == NULL)  
    {  
       throw("the given previous node cannot be NULL");        
       return;   
    }   
           
    // new temp node
    node* newNode = new node(); 

    newNode->data  = new_data; 

    // now the new node will point to thing to which prev node is pointing
    newNode->next = prevNode->next;  
   
    // prev node will point to new node
    prevNode->next = newNode; 
} 

// functiont to insert a element at the last
void append_SinglyLinkedList(node* head, int data) 
{ 
    node* newNode = new node(); 
  
    // initially let tail be head
    node *tail = head;  
   
    newNode->data  = data; 
    newNode->next = NULL; 
  

    // if the list is empty then make the head as new node
    if (head == NULL) 
    { 
       head = newNode; 
       return; 
    }   
       
    // else traverse to the last element
    while (tail->next != NULL) 
    {
        tail = tail->next; 
    }
        
    tail->next = newNode; 
    return;     
} 


// function to display elements
// pass the head of the linked list
// things will be seperated by the string seperator
void display_SinglyLinkedList(node* head , string seperator = " ")
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


  

#endif