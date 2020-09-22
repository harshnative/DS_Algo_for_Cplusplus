# Stacks  Header File -

A header file that as number of pre loaded methods on circular linked list

### Note - for the full code look into the stack.h file

# How to import - 

Download the stack.h header file and paste it into your source code folder and then write this in your .cpp file

```C++
#include "stack.h"
```

<br />


## Getting started - 

There are pre build stacks
1. StacksInt
2. StacksChar
3. StacksDouble

All stack are build using vector array's


```C++
StacksInt si;
StacksChar sc;
StacksDouble sd;
```

Now their are many opeartions as well like for every object

1. s.push()     for pushing an element in the stack

2. s.peek()     for getting the value of top element in stack

3. s.isStackempty()        to check if stack is empty or not - returns bool value

4. s.isStackFull()        to check if the stack is full or not

5. s.setMaxSize()       to set the max size of stack - by default it is 10

6. s.pop()         to remove as well as get the element on top

7. s.returnVector()         retuns the pointer to the vector stack



## sample program

```c++
#include<iostream>
#include<conio.h>
#include "stack.h"

using namespace std;


//for testing purpose
int main()
{
    StacksInt s;
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

```



## Diff applications of stack

1. reverseAString()     for reversing a string
2. checkBalancedParentheses()       for checking if the parenthesis are balanced in the string of not
3. toPostFixConvertor()     for converting the string to postfix form
4. postfixEvaluation()      for evaluating the postfix string


all the above application are implemented below


```c++
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
```