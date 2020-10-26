#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;


class QueueInt
{
    public:

    int maxSize = 10;

    vector <int> queue;

    int front = 0;
    int rear = -1;


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
    bool isEmpty()
    {
        if((this->front < 0) || (this->front > this->rear))
            return true;
        else
            return false;
    }


    // function to check if the stack is full or not


    bool isFull()
    {
        if(this->rear == this->maxSize-1)
            return true;
        else
            return false;
    }


    int peek()
    {
        return this->queue[this->front];
    }


    void enqueue(int data)
    {
        if(isFull())
        {
            throw "queue is full";
        }
        
        rear = rear + 1;
        this->queue.push_back(data);
    }


    int dequeue()
    {
        if(isEmpty())
        {
            throw "queue is empty";
        }
        else
        {
            int data = queue[this->front];
            front = front + 1;

            return data;
        }
    }


    vector <int> returnVector()
    {
        return this->queue;
    }

};



class QueueChar
{
    public:

    int maxSize = 10;

    vector <char> queue;

    int front = 0;
    int rear = -1;


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
    bool isEmpty()
    {
        if((this->front < 0) || (this->front > this->rear))
            return true;
        else
            return false;
    }


    // function to check if the stack is full or not


    bool isFull()
    {
        if(this->rear == this->maxSize-1)
            return true;
        else
            return false;
    }


    char peek()
    {
        return this->queue[this->front];
    }


    void enqueue(char data)
    {
        if(isFull())
        {
            throw "queue is full";
        }
        
        rear = rear + 1;
        this->queue.push_back(data);
    }


    char dequeue()
    {
        if(isEmpty())
        {
            throw "queue is empty";
        }
        else
        {
            char data = queue[this->front];
            front = front + 1;

            return data;
        }
    }


    vector <char> returnVector()
    {
        return this->queue;
    }

};




class QueueDouble
{
    public:

    int maxSize = 10;

    vector <double> queue;

    int front = 0;
    int rear = -1;


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
    bool isEmpty()
    {
        if((this->front < 0) || (this->front > this->rear))
            return true;
        else
            return false;
    }


    // function to check if the stack is full or not


    bool isFull()
    {
        if(this->rear == this->maxSize-1)
            return true;
        else
            return false;
    }


    double peek()
    {
        return this->queue[this->front];
    }


    void enqueue(double data)
    {
        if(isFull())
        {
            throw "queue is full";
        }
        
        rear = rear + 1;
        this->queue.push_back(data);
    }


    double dequeue()
    {
        if(isEmpty())
        {
            throw "queue is empty";
        }
        else
        {
            double data = queue[this->front];
            front = front + 1;

            return data;
        }
    }


    vector <double> returnVector()
    {
        return this->queue;
    }

};



#endif