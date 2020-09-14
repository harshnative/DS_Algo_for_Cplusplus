#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;


// node
struct node
{
    int data;
    node *next;
};









// circular linked list
class CircularLinkedList
{
    private:

        node *head;

    public:

        CircularLinkedList()
        {
            head = NULL;
        }


        node* generateHead(int data)
        {
            node *tmp = new node;
            tmp->data = data;
            tmp->next = tmp;

            head = tmp;

            return head;
        }
};


// function to traverse a circular linked list 
void display_CircularLinkedList(node* head , string seperator = " ")
{
    // new node points to head of linked list
    node *tmp;
    tmp = head;

    // should run only if linked list is not NULL
    if(tmp != NULL)
    {
    // loop will execute at least ones
    do 
    {
        cout << tmp->data <<seperator;
        tmp = tmp->next;

    } while((tmp != NULL));
    }
}


void addToEmpty_circularLinkedList(node* &head , int data)
{
    // this is only for empty list 
    if(head != NULL)
    {
        return;
    }


    node *tmp;
    tmp = new node();

    tmp->data = data;
    tmp->next = tmp;
}

#endif