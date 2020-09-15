#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

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


// function to delete all node with the key
void deleteWithKeyAll_singlyLinkedList(node* &head, int key) 
{ 

    // traversing the linked list till we get NULL or we found the key
    while(true)
    {
        try
        {
            deleteWithKey_singlyLinkedList(head , key);
        }
        catch(char const*)
        {
            break;
        }
    }
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


// function to get the lenght of linked list
int length_singlyLinkedList(node* head) 
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
        return elementPointer;

        pos++; 
    }

    return NULL;
} 


// function to return to pointer to a position from the end
// pointer will be NULL if element is not found
// position will be actual index + 1
node* returnPointerToPosFromLast(node* head , int posFromLast)
{ 
    int lenList = length_singlyLinkedList(head);
    int pos = lenList - posFromLast;

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


// function to count the  number of occurence in a key
int countKey_singlyLinkedList(node* head , int key) 
{ 
    // some pointers
    node *tmp;

    tmp = head;

    int keyCount = 0;

    // traversing the linked list till we get NULL
    while(tmp != NULL)
    {
        if(tmp->data == key)
        {
            keyCount++;
        }
        tmp = tmp->next;
    }

    return keyCount;
}




// loop detector in singly linked list
// returns a bool value
bool loopDetector_singlyLinkedList(node* head) 
{ 
    // some pointers
    vector <node*> hashTable;
    node *tmp;

    tmp = head;


    // traversing the linked list till we get NULL
    while(tmp != NULL)
    {
        if(std::count(hashTable.begin(), hashTable.end(), tmp)) // under algorithms
        {
            return true;
        }
        else
        {
            hashTable.push_back(tmp);
        }
        tmp = tmp->next;
    }

    return false;
}


// function to remove duplicate elements from unshorted list
void removeDuplicateUnshorted_singlyLinkedList(node* &head)
{
    struct node *ptr1, *ptr2, *tmp;
    ptr1 = head;
 
    // outter loop for iteration  
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
 
        // inner loop for deletion
        while (ptr2->next != NULL)
        {
            // if the current data is found further in the list
            if (ptr1->data == ptr2->next->data)
            {
                tmp = ptr2->next;
                ptr2->next = ptr2->next->next;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
} 

// function to find the middle of the linked list
// returns pointer to the middle node
node* middle_singlyLinkedList(node* head)
{
    int lengthLinkedList = length_singlyLinkedList(head);
    int middle = lengthLinkedList/2;

    if(middle % 2 != 0)
    {
        middle = middle +1;
    }

    return returnPointerToPos(head , middle);
}


// function to reverse the singly linked list
void reverse_singlyLinkedList(node* &head) 
{ 
    
    node* current = head; 
    node *prev = NULL, *next = NULL; 

    while (current != NULL) { 
        
        next = current->next; 

        current->next = prev; 

        prev = current; 
        current = next; 
    } 
    head = prev; 
} 

// function to return the pointer to the insertion point of two linked list 
// returns null if their is no insertion point
node* insertionPoint_singlyLinkedList(node* head1 , node* head2)
{
    while(head1 != NULL)
    {
        node* tmp;
        tmp = head2;

        while(tmp != NULL)
        {
            if(head1 == tmp)
            {
                return head1;
            }
            tmp = tmp->next;
        }
        head1 = head1->next;
    }
    return NULL;
}


// function to add two linked list
node* addTwoLinkedList(node* head1 , node* head2)
{
    SinglyLinkedList s;
    while (!((head1 == NULL) && (head2 == NULL)))
    {
        if(head1 == NULL)
        {
            s.addNode(head2->data);
            head2 = head2->next;
        }
        else
        if (head2 == NULL)
        {
           s.addNode(head1->data);
            head1 = head1->next;
        }
        else
        {
            s.addNode(head1->data + head2->data);
            head1 = head1->next;
            head2 = head2->next;
        }
        
        
    }
    
    return s.returnHead();
}








#endif