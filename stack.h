#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;


class StacksInt
{
    public:

    int maxSize = 10;

    vector <int> stack;

    int top = -1;


    // function to set the max size
    void setMaxSize(int size)
    {
        if(size < 1)
        {
            throw "size cannot be less than one";
        }
        this->maxSize = size;
    }


    // function to check if the array is empty or not
    bool isStackempty()
    {
        if(this->top == -1)
            return true;
        else
            return false;
    }


    // function to check if the stack is full or not


    bool isStackFull()
    {
        if(this->top == this->maxSize)
            return true;
        else
            return false;
    }


    int peek()
    {
        return this->stack.back();
    }


    void push(int data)
    {
        if(isStackFull())
        {
            throw "stack is full";
        }
        else
        {
            this->top = this->top + 1;
            this->stack.push_back(data);
        }
    }


    int pop()
    {
        if(isStackempty())
        {
            throw "stack is empty";
        }
        else
        {
            int toReturn = this->peek();
            this->stack.pop_back();
            this->top = this->top + -1;
            return toReturn;
        }
    }


    vector <int> returnVector()
    {
        return this->stack;
    }

};



class StacksDouble
{
    public:

    int maxSize = 10;

    vector <double> stack;

    int top = -1;


    // function to set the max size
    void setMaxSize(int size)
    {
        if(size < 1)
        {
            throw "size cannot be less than one";
        }
        this->maxSize = size;
    }


    // function to check if the array is empty or not
    bool isStackempty()
    {
        if(this->top == -1)
            return true;
        else
            return false;
    }


    // function to check if the stack is full or not


    bool isStackFull()
    {
        if(this->top == this->maxSize)
            return true;
        else
            return false;
    }


    double peek()
    {
        return this->stack.back();
    }


    void push(double data)
    {
        if(isStackFull())
        {
            throw "stack is full";
        }
        else
        {
            this->top = this->top + 1;
            this->stack.push_back(data);
        }
    }


    double pop()
    {
        if(isStackempty())
        {
            throw "stack is empty";
        }
        else
        {
            double toReturn = this->peek();
            this->stack.pop_back();
            this->top = this->top + -1;
            return toReturn;
        }
    }


    vector <double> returnVector()
    {
        return this->stack;
    }

};




class StacksChar
{
    public:

    int maxSize = 10;

    vector <char> stack;

    int top = -1;


    // function to set the max size
    void setMaxSize(int size)
    {
        if(size < 1)
        {
            throw "size cannot be less than one";
        }
        this->maxSize = size;
    }


    // function to check if the array is empty or not
    bool isStackempty()
    {
        if(this->top == -1)
            return true;
        else
            return false;
    }


    // function to check if the stack is full or not


    bool isStackFull()
    {
        if(this->top == this->maxSize)
            return true;
        else
            return false;
    }


    char peek()
    {
        return this->stack.back();
    }


    void push(char data)
    {
        if(isStackFull())
        {
            throw "stack is full";
        }
        else
        {
            this->top = this->top + 1;
            this->stack.push_back(data);
        }
    }


    char pop()
    {
        if(isStackempty())
        {
            throw "stack is empty";
        }
        else
        {
            char toReturn = this->peek();
            this->stack.pop_back();
            this->top = this->top + -1;
            return toReturn;
        }
    }


    vector <char> returnVector()
    {
        return this->stack;
    }

};



#endif