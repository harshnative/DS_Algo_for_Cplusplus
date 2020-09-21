#include<iostream>
#include<conio.h>
#include "stackChar.h"
#include <string> 

using namespace std;


void reverseAString()
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
}

bool checkBalancedParentheses(string myString)
{
    Stacks s;

    int lengthOfString = myString.size();
    
    for(int i=0 ; i<lengthOfString ; i++)
    {
        if((myString[i] == '{') || (myString[i] == '[') || (myString[i] == '('))
        {
            s.push(myString[i]);
        }

        if(myString[i] == '}')
        {
            if(!(s.pop() == '{'))
            {
                return false;
            }
        }

        if(myString[i] == ']')
        {
            if(!(s.pop() == '['))
            {
                return false;
            }
        }

        if(myString[i] == ')')
        {
            if(!(s.pop() == '('))
            {
                return false;
            }
        }
    }

    if(!s.isStackempty())
    {
        return false;
    }

    return true;
}



int returnPrecedenceOrder(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else
    if(c == '/')
    {
        return 2;
    }
    else
    if(c == '*')
    {
        return 2;
    }
    else
    if(c == '+')
    {
        return 1;
    }
    else
    if(c == '-')
    {
        return 1;
    }

    else
    {
        return -1;
    }
    
}


void toPostFixConvertor()
{

    // algo 
    // scan from left to right
    // 1. if the scanned char is an operand , output it
    // else
    // 2.1 if the precendence of the scanned operator is greator than the precedance of the operator in the stack top (or if stack is empty then push it)
    // 2.2 else pop the operator from the stack until the precedence of the scanned operator is less than or equal to precedence of the operator residing on the top of the stack. push the scanned operator

    // 2.3 if the scanned character is an "(" , push it
    // 2.4 if the scanned char is ")"" , pop and output from the stack until "(" is reached alsi one more pop to remove "("
    // repeat 1 and 2 until end
    // pop and output the stack until is empty

    Stacks s;
    
    string myString ;
    s.setMaxSize(100);
    string tempString = "";

    cout<<"enter the expression to be converted to postfix : ";
    getline(cin , myString);

    int lengthOfString = myString.size();

    for(int i=0 ; i<lengthOfString ; i++)
    {
        if((returnPrecedenceOrder(myString[i]) < 0) && (myString[i] != '(') && (myString[i] != ')'))
        {
            tempString = tempString + myString[i];
        }

        else
        if(s.isStackempty() || (returnPrecedenceOrder(myString[i]) > returnPrecedenceOrder(s.peek())))
        {
            s.push(myString[i]);
        }

        else
        if((!s.isStackempty()) && (myString[i] == '('))
        {
            s.push(myString[i]);
        }

        else
        if((!s.isStackempty()) && (myString[i] == ')'))
        {
            while(s.peek() != '(')
            {
                char data = s.pop();
                tempString = tempString + data;
            }
            s.pop();
        }

        else
        {

            while((!s.isStackempty()) && (returnPrecedenceOrder(myString[i]) <= returnPrecedenceOrder(s.peek())))
            {
                char data = s.pop();
                tempString = tempString + data;
            }

            s.push(myString[i]);
        }

                
    }
            

    

    while(!s.isStackempty())
    {
        char data = s.pop();
        tempString = tempString + data;
    }

    cout<<"\nconverted string = "<<tempString;
}


//for testing purpose
int main()
{
    // reverseAString();
    toPostFixConvertor();
    getch();
	return 0;
}

