#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;


// queue data stucture class
class QueueInt
{
    public:

    // max size of queue
    int maxSize = 10;
    int front = -1;
    int rear = -1;
    vector <int> queue;

    // initialising the array to max size with zero
    QueueInt(int maxSize = 10)
    {
        this->maxSize = maxSize;
        while(maxSize--)
        {
            this->queue.push_back(0);
        }
    }

    // function to check if the array is empty or not
    bool isEmpty()
    {
        if((this->front == -1) || (this->front > this->rear))
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

    // function to get the element at front without removing it
    int peek()
    {
        return this->queue[this->front];
    }

    // function to get the element at rear
    int peek0()
    {
        return this->queue[this->rear];
    }

    // function to insert a data into queue
    void enqueue(int data)
    {
        /* Algo - 
        1. check if the queue is full return
        2. if the front is -1 make it to 0
        3. increment rear 
        4. add data to queue[rear] */

        if(isFull())
        {
            throw "queue is full";
        }

        else
        {
            if(this->front == -1)
            {
                this->front = 0;
            }

            this->rear++;
            this->queue[this->rear] = data;
        }
    }

    // fucntion to remove a data from queue
    int dequeue()
    {
        /* Algo - 
        1. check for empty return
        2. store queue[front] in temp var
        3. increment front */


        if(isEmpty())
        {
            throw "queue is empty";
        }
        
        else
        {
            int data = this->queue[this->front];
            this->queue[this->front] = 0;
            this->front++;

            return data;
        }
    }


    // function to get the refenerce to the array
    vector <int> returnVector()
    {
        return this->queue;
    }

};



class QueueDouble
{
    public:

    int maxSize = 10;
    int front = -1;
    int rear = -1;
    vector <double> queue;

    QueueDouble(int maxSize = 10)
    {
        this->maxSize = maxSize;
        while(maxSize--)
        {
            this->queue.push_back(0.0);
        }
    }

    // function to check if the array is empty or not
    bool isEmpty()
    {
        if((this->front == - 1) || (this->front > this->rear))
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

        else
        {
            if(this->front == -1)
            {
                this->front = 0;
            }

            this->rear++;
            this->queue[this->rear] = data;
        }
    }


    double dequeue()
    {
        if(isEmpty())
        {
            throw "queue is empty";
        }
        
        else
        {
            double data = this->queue[this->front];
            this->queue[this->front] = 0;
            this->front++;

            return data;
        }
    }


    vector <double> returnVector()
    {
        return this->queue;
    }

};




class QueueChar
{
    public:

    int maxSize = 10;
    int front = -1;
    int rear = -1;
    vector <char> queue;

    QueueChar(int maxSize = 10)
    {
        this->maxSize = maxSize;
        while(maxSize--)
        {
            this->queue.push_back(' ');
        }
    }

    // function to check if the array is empty or not
    bool isEmpty()
    {
        if((this->front == - 1) || (this->front > this->rear))
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

        else
        {
            if(this->front == -1)
            {
                this->front = 0;
            }

            this->rear++;
            this->queue[this->rear] = data;
        }
    }


    char dequeue()
    {
        if(isEmpty())
        {
            throw "queue is empty";
        }
        
        else
        {
            char data = this->queue[this->front];
            this->queue[this->front] = 0;
            this->front++;

            return data;
        }
    }


    vector <char> returnVector()
    {
        return this->queue;
    }

};





class CircularQueueInt
{
    public:

    int maxSize = 10;

    vector <int> queue;

    int front = -1;
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
        if(this->front == -1)
            return true;
        else
            return false;
    }


    // function to check if the stack is full or not


    bool isFull()
    {
        if(((this->front == 0) && (this->rear == this->maxSize-1)) || (this->rear + 1 == front))
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

        if(this->front == -1)
        {
            front = 0;
            rear = 0;
        }

        else 
        {
            if (rear == this->maxSize - 1)
            rear = 0;
            else
            rear = rear + 1;
        }
        this->queue[rear] = data;
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


#endif