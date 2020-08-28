# Linked list Header File -

A header file that as number of pre loaded methods on linked list


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

    cout<<"\nAfter entire linked list \n";
    deleteEntire_singlyLinkedList(head);
    display_SinglyLinkedList(head); 
}


int main()
{
    singlyList();
    getch();
    return 0;
}
```
