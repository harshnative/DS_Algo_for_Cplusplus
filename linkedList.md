# Linked list Header File -

A header file that as number of pre loaded methods on linked list


# How to import - 

Download the linkedList.h header file and paste it into your source code folder and then write this in your .cpp file

```C++
#include "linkedList.h"
```

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

