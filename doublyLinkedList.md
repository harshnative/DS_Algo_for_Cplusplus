# Doubly Linked list Header File -

A header file that as number of pre loaded methods on doubly linked list

### Note - for the full code look into the doublyLinkedList.h file

# How to import - 

Download the doublyLinkedList.h header file and paste it into your source code folder and then write this in your .cpp file

```C++
#include "doublyLinkedList.h"
```

#### Note - All Function are made with single data in mind , you have to change the struct node and add more data operations in the doublyLinkedList.h according to your use

<br />

#### Note - All data is considered to be in integer form

## Generating a new linked list - 

```C++
DoublyLinkedList dl;
node *head = dl.generateHead(10);
```


<br />
Now you can display every element in the linked list by passing this head pointer to this function

```C++
string seperator = ","
displayFromHead_doublyLinkedList(head , seperator)
```


## Additional methods - 


let Head be the pointer to the linked list

#### Note - Position is considered like actual index + 1

<br />
<br />

1. #### add node at the beginning of the linked list

```C++
// function to add to the beginning of the doubly linked list
void addToBeginning_doublyLinkedList(node* &head , int data)
```

<br />
<br />


2. #### display from head

```C++

// function to display elements
// pass the head of the linked list
// things will be seperated by the string seperator
void displayFromHead_doublyLinkedList(node* head , string seperator = " ")
```

<br />
<br />


3. #### display from tail

```C++
// function to display elements
// pass the tail of the linked list
// things will be seperated by the string seperator
void displayFromTail_doublyLinkedList(node* tail , string seperator = " ")
```

<br />
<br />



4. #### get the lenght of linked list

```C++
// function to find the size of linked list 
// keep one NULL and pass the value of other
int size_doublyLinkedList(node* head = NULL , node* tail = NULL)
```

<br />
<br />




# Sample program -
```c++
    #include<iostream>
    #include<conio.h>

    #include "doublyLinkedList.h"

    using namespace std;

    void doublyLinkedList()
    {
        DoublyLinkedList dl;

        node *head = dl.generateHead(10);

        cout<<"initialLinkedList"<<endl;
        displayFromHead_doublyLinkedList(head);

        addToBeginning_doublyLinkedList(head, 29);
        cout<<"\nafter adding 29 to start"<<endl;
        displayFromHead_doublyLinkedList(head);

        addToBeginning_doublyLinkedList(head, 58);
        cout<<"\nafter adding 58 to start"<<endl;
        displayFromHead_doublyLinkedList(head);

        cout<<"\nsize by passing head = "<<size_doublyLinkedList(head)<<endl;
    }


    int main()
    {
        doublyLinkedList();
        getch();
        return 0;
    }
```
