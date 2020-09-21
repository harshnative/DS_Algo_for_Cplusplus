#include<iostream>
#include<conio.h>
#include "stack.h"
#include <string> 

using namespace std;


//for testing purpose
int main()
{
    Stacks s;
    
    string myString;

    cout<<"enter the string to reverse : ";
    getline(cin , myString);

    int lengthOfString = myString.size();

    for(int i=0 ; i<lengthOfString ; i++)
    {
        s.push(myString[i]);
    }

    cout<<endl;
    
    // print stack data it will be automatically in reverse order
    while(!s.isStackempty()) {
        char data = s.pop();
        cout<<data;
    }


	return 0;
}

