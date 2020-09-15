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