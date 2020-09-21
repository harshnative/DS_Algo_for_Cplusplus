#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;


class Stacks
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
        return this->stack[this->top];
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
            char toReturn = this->stack[this->top];
            stack.pop_back();
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