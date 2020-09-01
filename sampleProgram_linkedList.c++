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