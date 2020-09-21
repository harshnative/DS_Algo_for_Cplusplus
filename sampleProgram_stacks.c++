#include<iostream>
#include<conio.h>
#include "stack.h"

using namespace std;


//for testing purpose
int main()
{
    Stacks s;
    s.setMaxSize(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // print stack data 
    while(!s.isStackempty()) {
        int data = s.pop();
        cout<<"\n"<<data;
    }

    // press enter to continue 
    getch();
	return 0;
}

