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
}


int main()
{
    singlyList();
    getch();
    return 0;
}