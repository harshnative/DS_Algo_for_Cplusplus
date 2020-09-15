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