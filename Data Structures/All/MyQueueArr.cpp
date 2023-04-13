#include<bits/stdc++.h>
using namespace std;

template<class T>
class MyQueue{

    T * arr;
    int front,rear,len,capacity;

    void expand()
    {
        int newcapacity;
        if(capacity == 0)
        {
            newcapacity = 1;
        }
        else
        {
            newcapacity = 2*capacity;
        }
        T *newarr = new T[newcapacity];

        for(int i=0;i<len;i++)
        {
            newarr[i] = arr[i];
        }
        capacity = newcapacity;
        if(len>0)
        {
            delete [] arr;
        }
        arr = newarr;

    }
    void shrink()
    {
        int newcapacity;
        newcapacity = capacity/2;

        T *newarr = new T[newcapacity];

        for(int i=0;i<len;i++)
        {
            newarr[i] = arr[i];
        }
        capacity = newcapacity;
        if(len>0)
        {
            delete [] arr;
        }
        arr = newarr;
    }
    void leftShift()
    {
        for(int i=0;i<len-1;i++)
        {
            arr[i] = arr[i+1];
        }
    }

public:
    MyQueue(int X = 1)  // given capacity
    {
        arr = new T[X];
        len = 0;
        capacity = X;
        front = 0;
        rear = -1;  // No element yet
    }
    MyQueue(int X, int Y, T *data)  // Initialize with the values of given array
    {
        arr = new T[X];
        for(int i=0;i<Y;i++)
            arr[i] = data[i];
        len = Y;
        capacity = X;
        front = 0;
        rear = len-1;
    }
    ~MyQueue()
    {
        delete [] arr;
    }
    int length()  // O(1)
    {
        return len;
    }
    void enqueue(T item)  // O(1)
    {
        if(len==capacity)
        {
            expand();
        }
        rear++;
        arr[rear] = item;
        len++;
    }
    T dequeue()
    {
        if(len==0)
        {
            cout<<"Cannot dequeue from empty queue.\n";
            T dummy;
            return dummy;
        }
        T ans = arr[front];
        leftShift();  // O(n)
        rear--;
        len--;
        if(len <= capacity/2)
        {
            shrink();
        }
        return ans;
    }
    T leaveQueue()
    {
        if(len==0)  // Empty Queue
        {
            cout<<"Cannot call leaveQueue on empty queue\n";
            T dummy;
            return dummy;
        }
        T ans = arr[rear--];
        len--;
        if(len <= capacity/2)
        {
            shrink();
        }
        return ans;
    }
    T frontValue()  // O(1)
    {
        if(len==0)
        {
            cout<<"Queue is Empty\n";
            T dummy;
            return dummy;
        }
        return arr[front];
    }
    T rearValue()  // O(1)
    {
        if(len==0)
        {
            cout<<"Queue is Empty\n";
            T dummy;
            return dummy;
        }
        return arr[rear];
    }
    void clear()
    {
        if(arr)
            delete [] arr;
        arr = new T[1];
        len = 0;
        capacity = 1;
        front = 0;
        rear = -1;
    }
    void print()
    {
        cout<<"Queue : ";
        if(len==0)
        {
            cout<<"<>\n";
            return;
        }
        cout<<"< |";
        for(int i=0;i<len;i++)
        {
            cout<<" "<<arr[i];
        }
        cout<<">\n";
    }

};
