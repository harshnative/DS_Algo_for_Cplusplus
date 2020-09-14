#include<iostream>
#include<conio.h>

#include "circularLinkedList.h"

using namespace std;

void circularLinkedList()
{
    CircularLinkedList cl;

    node *head = cl.generateHead(10);

    cout<<"initialLinkedList"<<endl;
    display_CircularLinkedList(head);
}

void testing_InsertionINList()
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
}





int main()
{
    // circularLinkedList();
    testing_InsertionINList();
    getch();
    return 0;
}