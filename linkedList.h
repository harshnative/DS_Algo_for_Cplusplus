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

// function to insert a element at the last
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



// function to delete a node with the key
void deleteWithKey_singlyLinkedList(node* &head, int key) 
{ 
    // some pointers
    node *tmp , *previousNode;
    tmp = head;

    // if the head is the key itself then we have to make the next element of list to be head
    if(tmp->data == key)
    {
        head = tmp->next;
        free(tmp);
        return;
    }

    // traversing the linked list till we get NULL or we found the key
    while(tmp != NULL && tmp->data != key)
    {
        previousNode = tmp;
        tmp = tmp->next;
    }

    // if the key is not found then throw error
    if(tmp == NULL)
    {
        throw("deletion not possible");
    }

    // make the previous node to point to next node
    previousNode->next = tmp->next;
    free(tmp);
} 


// function to delete a linked list
void deleteEntire_singlyLinkedList(node* &head) 
{ 
    // some pointers
    node *tmp , *current;
    current = head;


    // traversing the linked list till we get NULL
    while(current != NULL)
    {
        tmp = current->next;
        free(current);
        current = tmp->next;
    }

    head = NULL;
} 
  

// function to delete a node with the position
// position is consider to be head as 1 and next element from head as two 
void deleteWithPos_singlyLinkedList(node* &head, int pos) 
{ 
    // some pointers
    node *tmp , *previousNode;
    tmp = head;

    int tmpCount = 1;

    // if the head is the pos itself then we have to make the next element of list to be head
    if(pos == 1)
    {
        head = tmp->next;
        free(tmp);
        return;
    }

    // traversing the linked list till we get NULL or we reach that position
    while(tmp != NULL && tmpCount != pos)
    {
        previousNode = tmp;
        tmp = tmp->next;
        tmpCount++;
    }

    // if the key is not found then throw error
    if(tmp == NULL)
    {
        throw("deletion not possible");
    }

    // make the previous node to point to next node
    previousNode->next = tmp->next;
    free(tmp);
} 


// function to delete a linked list
int length_singlyLinkedList(node* &head) 
{ 
    // some pointers
    node *tmp;

    tmp = head;

    int listCount = 0;

    // traversing the linked list till we get NULL
    while(tmp != NULL)
    {
        tmp = tmp->next;
        listCount++;
    }

    return listCount;
} 


// function to search for an element and return the 
// pointer will be NULL if element is not found
node* returnPointerToElement(node* head , int element)
{ 
    // some pointers
    node *tmp , *elementPointer;

    tmp = head;
    
    int pos = 1;

    // traversing the linked list till we get NULL
    while(tmp != NULL && tmp->data == element)
    {
        tmp = tmp->next;

        elementPointer = returnPointerToPos(head , pos);
        pos++; 
    }

    if(tmp == NULL)
    {
        elementPointer = NULL;
    }

    return elementPointer;
} 




#endif