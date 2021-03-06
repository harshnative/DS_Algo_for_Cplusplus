#include<iostream>
#include<conio.h>
#include "stack.h"
#include <string> 
#include <math.h>

using namespace std;


void reverseAString()
{
    StacksChar s;
    
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
    StacksChar s;

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
        return 4;
    }
    else
    if(c == '/')
    {
        return 3;
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
        return 0;
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

    StacksChar s;
    
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





void postfixEvaluation()
{

    // algo
    // 1) Create a stack to store operands (or values).
    // 2) Scan the given expression and do following for every scanned element.
    // …..a) If the element is a number, push it into the stack
    // …..b) If the element is a operator, pop operands for the operator from stack. Evaluate the operator and push the result back to the stack
    // 3) When the expression is ended, the number in the stack is the final answer
    
    
    StacksDouble s;
    
    string myString ;
    s.setMaxSize(100);

    cout<<"enter the expression to be evaluated : ";
    getline(cin , myString);

    int lengthOfString = myString.size();

    for(int i=0 ; i<lengthOfString ; i++)
    {
        if(myString[i] == '^')
        {
            double x = s.pop();
            double y = s.pop();

            double result = pow(y,x);
            s.push(result);
        }
        else
        if(myString[i] == '/')
        {
            double x = s.pop();
            double y = s.pop();

            double result = y/x;
            s.push(result);
        }
        else
        if(myString[i] == '*')
        {
            double x = s.pop();
            double y = s.pop();

            double result = y*x;
            s.push(result);
        }
        else
        if(myString[i] == '+')
        {
            double x = s.pop();
            double y = s.pop();

            double result = y+x;
            s.push(result);

        }
        else
        if(myString[i] == '-')
        {
            double x = s.pop();
            double y = s.pop();

            double result = y-x;
            s.push(result);
        }
        else
        {
            double toPush = (double)(myString[i]) - 48;
            s.push(toPush);
        }
    }

    cout<<"\nResult = "<<endl;
    cout<<s.pop();
}


//for testing purpose
int main()
{
    reverseAString();


    string myString ;
    cout<<"enter the expression to be evaluated : ";
    getline(cin , myString);
    cout<<"result = "<<checkBalancedParentheses(myString);


    toPostFixConvertor();
    postfixEvaluation();
    getch();
	return 0;
}

