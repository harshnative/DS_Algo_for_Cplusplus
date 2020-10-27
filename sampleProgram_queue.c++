#include<iostream>
#include<conio.h>
#include "queue.h"

using namespace std;


//for testing purpose
int main()
{
    QueueInt s;
    s.enqueue(10);
    s.enqueue(20);
    s.enqueue(30);
    s.enqueue(40);
    s.dequeue();
    s.enqueue(50);


    // print stack data 
    while(!s.isEmpty()) {
        int data = s.dequeue();
        cout<<"\n"<<data;
    }

    // press enter to continue 
    getch();
	return 0;
}
