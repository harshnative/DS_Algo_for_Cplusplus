# Circular Linked list Header File -

A header file that as number of pre loaded methods on circular linked list

### Note - for the full code look into the circularLinkedList.h file

# How to import - 

Download the circularLinkedList.h header file and paste it into your source code folder and then write this in your .cpp file

```C++
#include "circularLinkedList.h"
```

#### Note - All Function are made with single data in mind , you have to change the struct node and add more data operations in the circularLinkedList.h according to your use

<br />

#### Note - All data is considered to be in integer form

## Generating a new linked list - 

```C++
// By class
CircularLinkedList cl;
node* head = generateHead(head);


// by simple method
node* head = NULL;
addToEmpty_circularLinkedList(head , 29);
```


<br />
Now you can display every element in the linked list by passing this head pointer to this function

```C++
string seperator = ","
display_CircularLinkedList(head,seperator);
```


## Additional methods - 


let Head be the pointer to the linked list

#### Note - Position is considered like actual index + 1

<br />
<br />

1. #### return the last node of the circular linked list 

```C++
// function to return last node of a circular linked list 
node* returnLastNode_circularLinkedList(node* head)
```

<br />
<br />


2. #### add to a empty circular linked list

```C++
// function to add a node to a empty circular list
void addToEmpty_circularLinkedList(node* &head , int data)
```

<br />
<br />


3. #### add to the beginning in a circular linked list

```C++
// function to add at the beginning of the circular linked list
void addTobeginning_circularLinkedList(node* &head , int data)
```

<br />
<br />


4. #### add after a certain position in linked list 

```C++
// function to add after a certain position in circular linked list
// position starts from one
// if you pass 2 as pos to add 10 on a linked list which is 1 -> 2 -> 3 then it will become 1 -> 10 -> 2 -> 3
// it will add on that position not after that position
// throws const char * error if the position is out of scope
void addToAfterPos_circularLinkedList(node* &head , int pos , int data)
```

<br />
<br />


5. #### add to the end of the linked list

```C++
// function to add a node at the end of circular linked list
void addToEnd_circularLinkedList(node* &head , int data)
```

<br />
<br />


6. #### check whether a linked list is circular or note

```C++
// check if a linked list is circular or not
// also returns False if the linked list is empty 
bool IsCircularLinkedList(node* head)
```

<br />
<br />


7. #### delete a node at a certain position in circular linked list

```C++

// function to delete a node in a circular linked list
// throws a char const * error if a pos is not found
// pos is consider from 1
// deletes a node at that position not after that position 
void deletePos_circularLinkedList(node* &head , int pos)
```

<br />
<br />


8. #### get a node position of the first apperance of the key

```C++
// function to return a position of a first appearance of a key in linked list
// position starts from one
// returns 0 if pos is not found
int returnNodePosToAKey_circularLinkedList(node* head , int key)
```

<br />
<br />


9. #### get a node after a certain pos

```C++
// function to return a pointer of a pos 
// position starts from one
// returns NULL if pos is out of scope
node* returnNodeToAPos_circularLinkedList(node* head , int pos)
```

<br />
<br />


10. #### get the lenght of linked list

```C++
// function to find size of circular linked list
int size_CircularLinkedList(node* head)
```

<br />
<br />




# Sample program -
```c++
#include<iostream>
#include<conio.h>

#include "circularLinkedList.h"

using namespace std;


void circularLinkedList()
{
    node* head = NULL;

    addToEmpty_circularLinkedList(head , 29);

    cout<<"intial list"<<endl;
    display_CircularLinkedList(head);

    addTobeginning_circularLinkedList(head , 10);

    cout<<"\nafter adding 10 at beginning"<<endl;
    display_CircularLinkedList(head);


    addToAfterPos_circularLinkedList(head , 2 , 52);

    cout<<"\nafter adding 52 at pos = 2"<<endl;
    display_CircularLinkedList(head);


    addToEnd_circularLinkedList(head , 58);

    cout<<"\nafter adding 58 at last"<<endl;
    display_CircularLinkedList(head);

    cout<<"\nis this a linked list = "<<IsCircularLinkedList(head);

    deletePos_circularLinkedList(head , 3);

    cout<<"\nafter deleting element at pos = 3"<<endl;
    display_CircularLinkedList(head);

    cout<<"\npos of key = 10 is "<<returnNodePosToAKey_circularLinkedList(head , 10);

    cout<<"\nnode at pos = 2"<<returnNodeToAPos_circularLinkedList(head , 2);

    cout<<"\nsize of linked list = "<<size_CircularLinkedList(head);


}





int main()
{
    circularLinkedList();
    getch();
    return 0;
}

```
