# Linked list Header File -

A header file that as number of pre loaded methods on linked list

### Note - for the full code look into the linkedList.h file

# How to import - 

Download the linkedList.h header file and paste it into your source code folder and then write this in your .cpp file

```C++
#include "linkedList.h"
```

#### Note - All Function are made with single data in mind , you have to change the struct node and add more data operations in the linkedList.h according to your use

<br />

#### Note - All data is considered to be in integer form

## Generating a new linked list - 

```C++
// creating a object of singly linked list class 
SinglyLinkedList s;

s.addNode(data);
s.addNode(data);
s.addNode(data);

// now the linked list will have 3 elements
```

<br />
Now get the pointer to the head for the linked list

```C++
node *head = s.returnHead();
```

<br />
Now you can display every element in the linked list by passing this head pointer to this function

```C++
string seperator = ","
display_SinglyLinkedList(head,seperator);
```


## Additional methods - 

### For singly linked list

let Head be the pointer to the linked list

#### Note - Position is considered like actual index + 1

<br />
<br />

1. #### insert element at the starting of the singly linked list

```C++
// function for pushing the element at the top of linked list
// pass the head of the linked list
void push_SinglyLinkedList(node* &head_ref, int new_data)  
```

<br />
<br />


2. #### get the node pointer pointing to a certain position in singly linked list

```C++
// returns the pointer to a certain position in a linked list
// position is like index + 1 
node* returnPointerToPos(node* head , int pos)
```

<br />
<br />


3. #### insert element after a certain node in singly linked list

```C++
// function for insert a element after a certain node
// pass the prevNode value
// you can get the previous node pointer using returnPointerToPos() function 
void insertAfterCertainNode_SinglyLinkedList(node* prevNode, int new_data)
```

<br />
<br />


4. #### insert element at the end of the list

```C++
// function to insert a element at the last
void append_SinglyLinkedList(node* head, int data) 
```

<br />
<br />


5. #### delete the element in the linked list with the help of key

```C++
// function to delete a node with the key
void deleteWithKey_singlyLinkedList(node* &head, int key) 
```

<br />
<br />


6. #### delete the element in the linked list with the help of position

```C++
// function to delete a node with the position
// position is consider to be head as 1 and next element from head as two 
void deleteWithPos_singlyLinkedList(node* &head, int pos) 
```

<br />
<br />


7. #### delete the entire linked list

```C++

// function to delete a entire linked list
void deleteEntire_singlyLinkedList(node* &head, int pos) 
```

<br />
<br />


8. #### delete the entire linked list

```C++

// function to delete a entire linked list
void deleteEntire_singlyLinkedList(node* &head, int pos) 
```

<br />
<br />


9. #### get the pointer to a certain element

```C++
// function to search for an element and return the 
// pointer will be NULL if element is not found
node* returnPointerToElement(node* head , int element)
```

<br />
<br />


10. #### get the lenght of linked list

```C++
// function to get the lenght of linked list
int length_singlyLinkedList(node* head) 
```

<br />
<br />

11. #### get the lenght of linked list

```C++
// function to return to pointer to a position from the end
// pointer will be NULL if element is not found
// position will be actual index + 1
node* returnPointerToPosFromLast(node* head , int posFromLast)
```

<br />
<br />

12. #### get the pointer to certain element  of linked list

```C++
// function to search for an element and return the 
// pointer will be NULL if element is not found
node* returnPointerToElement(node* head , int element)
```

<br />
<br />


13. #### get the pointer to pos from last in linked list

```C++
// function to return to pointer to a position from the end
// pointer will be NULL if element is not found
// position will be actual index + 1
node* returnPointerToPosFromLast(node* head , int posFromLast)
```

<br />
<br />


14. #### get the number of occurence of a key in singly linked list

```C++
// function to count the  number of occurence in a key
int countKey_singlyLinkedList(node* head , int key) 
```

<br />
<br />

15. #### deteck a loop in singly linked list 


```C++
// loop detector in singly linked list
// returns a bool value
bool loopDetector_singlyLinkedList(node* head) 
```

<br />
<br />

16. #### remove the duplicates element from a list 


```C++
// function to remove duplicate elements from unshorted list
void removeDuplicateUnshorted_singlyLinkedList(node* &head)
```

<br />
<br />


17. #### find the middle of linked list


```C++
// function to find the middle of the linked list
// returns pointer to the middle node
node* middle_singlyLinkedList(node* head)
```

<br />
<br />

17. #### to reverse a singly linked list

```C++
// function to reverse the singly linked list
void reverse_singlyLinkedList(node* &head) 
```

<br />
<br />


18. #### get the insertion point of two list

```C++
// function to return the pointer to the insertion point of two linked list 
// returns null if their is no insertion point
node* insertionPoint_singlyLinkedList(node* head1 , node* head2)
```

<br />
<br />

19. #### add two linked list

```C++
// function to add two linked list
node* addTwoLinkedList(node* head1 , node* head2)
```

<br />
<br />



# Sample program -
```c++
#include<iostream>
#include<conio.h>

#include "linkedList.h"

using namespace std;

void singlyList()
{
    int n;
    cout<<"Enter the no elements in linked list : ";
    cin>>n;

    SinglyLinkedList s;

    for(int i=0 ; i<n ; i++)
    {
        int data;
        cout<<"Enter the data - ";
        cin>>data;
        s.addNode(data);
    }

    node *head = s.returnHead();

    cout<<"\nLinked list = \n";
    display_SinglyLinkedList(head);    

    cout<<"\nAfter pushing value = 10 at start\n";
    push_SinglyLinkedList(head , 10);  
    display_SinglyLinkedList(head); 


    cout<<"\nAfter pushing value = 29 after 3rd position\n";
    node *pointerTo3Element = returnPointerToPos(head , 3);
    insertAfterCertainNode_SinglyLinkedList(pointerTo3Element , 29);  
    display_SinglyLinkedList(head); 

    cout<<"\nAfter appending value = 52\n";
    append_SinglyLinkedList(pointerTo3Element , 52);  
    display_SinglyLinkedList(head); 

    cout<<"\nAfter deleting value with key method = 29\n";
    deleteWithKey_singlyLinkedList(head , 29);
    display_SinglyLinkedList(head); 

    cout<<"\nAfter deleting element at pos = 3\n";
    deleteWithPos_singlyLinkedList(head , 3);
    display_SinglyLinkedList(head); 

    cout<<"\nlength of linked list\n";
    int len = length_singlyLinkedList(head);
    cout<<len; 

    cout<<"\npointer to the element = 1\n";
    cout<<returnPointerToElement(head , 1);

    cout<<"\ncounting 1 in linked list \n";
    cout<<countKey_singlyLinkedList(head , 1);

    cout<<"\nAfter deleting entire linked list \n";
    deleteEntire_singlyLinkedList(head);
    display_SinglyLinkedList(head); 
}

void testingLoopDetector_singlyLinkedList()
{
    // making a new list for loop detection
    SinglyLinkedList s1;

    s1.addNode(52);

    node *head1 = s1.returnHead(); 
  
    append_SinglyLinkedList(head1, 20); 
    append_SinglyLinkedList(head1, 4); 
    append_SinglyLinkedList(head1, 15); 
    append_SinglyLinkedList(head1, 10); 
  
    /* Create a loop for testing */
    head1->next->next->next->next = head1;  

    cout<<"is their loop in new list - "<<endl;
    cout<<"\n"<<loopDetector_singlyLinkedList(head1);
    
}


void testingDuplicateRemover_singlyLinkedList()
{
    // making a new list for loop detection
    SinglyLinkedList s1;

    s1.addNode(12);

    node *head1 = s1.returnHead(); 
  
    append_SinglyLinkedList(head1, 11); 
    append_SinglyLinkedList(head1, 12); 
    append_SinglyLinkedList(head1, 24); 
    append_SinglyLinkedList(head1, 12); 
    append_SinglyLinkedList(head1, 24); 
  
    cout<<"list = "<<endl;
    display_SinglyLinkedList(head1);

    cout<<"\nafter removing duplicatelist - "<<endl;
    removeDuplicateUnshorted_singlyLinkedList(head1);
    display_SinglyLinkedList(head1);
    
}


void testingMiddle_singlyLinkedList()
{
    SinglyLinkedList s1;

    s1.addNode(12);

    node *head1 = s1.returnHead(); 
  
    append_SinglyLinkedList(head1, 1); 
    append_SinglyLinkedList(head1, 2); 
    append_SinglyLinkedList(head1, 4); 
    append_SinglyLinkedList(head1, 6); 
    append_SinglyLinkedList(head1, 24);
    append_SinglyLinkedList(head1, 45);

    cout<<"list = "<<endl;
    display_SinglyLinkedList(head1);

    cout<<"\nmiddle = "<<endl;

    node* middleNode = middle_singlyLinkedList(head1);

    cout<<middleNode->data;
}


void testingDeleteAllKey_singlyLinkedList()
{
    // making a new list for loop detection
    SinglyLinkedList s1;

    s1.addNode(12);

    node *head1 = s1.returnHead(); 
  
    append_SinglyLinkedList(head1, 11); 
    append_SinglyLinkedList(head1, 12); 
    append_SinglyLinkedList(head1, 24); 
    append_SinglyLinkedList(head1, 12); 
    append_SinglyLinkedList(head1, 24); 
  
    cout<<"list = "<<endl;
    display_SinglyLinkedList(head1);

    cout<<"\nafter removing all 12 - "<<endl;
    deleteWithKeyAll_singlyLinkedList(head1 , 12);
    display_SinglyLinkedList(head1);
    
}

void testingReverse_singlyLinkedList()
{
    SinglyLinkedList s1;

    s1.addNode(12);

    node *head1 = s1.returnHead(); 
  
    append_SinglyLinkedList(head1, 11); 
    append_SinglyLinkedList(head1, 12); 
    append_SinglyLinkedList(head1, 24); 
    append_SinglyLinkedList(head1, 12); 
    append_SinglyLinkedList(head1, 24); 
  
    cout<<"list = "<<endl;
    display_SinglyLinkedList(head1);

    cout<<"\nafter reversing - "<<endl;
    reverse_singlyLinkedList(head1);
    display_SinglyLinkedList(head1);
}


void testingInsertionPoint_singlyLinkedList()
{
    node* newNode; 
  
    // Addition of new nodes 
    node* head1 = new node(); 
    head1->data = 10; 
  
    node* head2 = new node(); 
    head2->data = 3; 
  
    newNode = new node(); 
    newNode->data = 6; 
    head2->next = newNode; 
  
    newNode = new node(); 
    newNode->data = 9; 
    head2->next->next = newNode; 
  
    newNode = new node(); 
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = new node(); 
    newNode->data = 30; 
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL; 

    cout<<"list 1 = "<<endl;
    display_SinglyLinkedList(head1);

    cout<<"\nlist 2 = "<<endl;
    display_SinglyLinkedList(head2);

    cout<<"\ninsertion point is - "<<insertionPoint_singlyLinkedList(head1 , head2)->data;

}

void testingAddTwoLinkedList()
{
    SinglyLinkedList s1  , s2;
    int m , n;

    cout<<"enter the no of element in first list : ";
    cin>>m;
    cout<<"enter the no of element in second list : ";
    cin>>n;

    cout<<"\nenter the first list elements\n";
    for(int i=0 ; i<m ; i++)
    {
        int tmp;
        cin>>tmp;
        s1.addNode(tmp);
    }


    cout<<"\nenter the second list elements\n";
    for(int i=0 ; i<n ; i++)
    {
        int tmp;
        cin>>tmp;
        s2.addNode(tmp);
    }


    node* head1 = s1.returnHead();
    node* head2 = s2.returnHead();

    cout<<"\n\nfirst List = "<<endl;
    display_SinglyLinkedList(head1);

    cout<<"\n\nsecond List = "<<endl;
    display_SinglyLinkedList(head2);

    node* added = addTwoLinkedList(head1 , head2);

    cout<<"\n\nadded List = "<<endl;
    display_SinglyLinkedList(added);
}

int main()
{
    // singlyList();
    // testingLoopDetector_singlyLinkedList();
    // testingDeleteAllKey_singlyLinkedList();
    // testingMiddle_singlyLinkedList();
    // testingReverse_singlyLinkedList();
    // testingInsertionPoint_singlyLinkedList();
    testingAddTwoLinkedList();
    getch();
    return 0;
}
```
