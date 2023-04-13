#include<bits/stdc++.h>
using namespace std;

template<class T>
class MyStack{

    T * arr;
    int top,capacity;  // length = top = first unused position

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

        for(int i=0;i<top;i++)
        {
            newarr[i] = arr[i];
        }
        capacity = newcapacity;
        if(top>0)
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

        for(int i=0;i<top;i++)
        {
            newarr[i] = arr[i];
        }
        capacity = newcapacity;
        if(top>0)
        {
            delete [] arr;
        }
        arr = newarr;
    }

public:
    MyStack(int X = 1)  // given capacity
    {
        arr = new T[X];
        top = 0;
        capacity = X;
    }
    MyStack(int X, int Y, T *data)  // Initialize with the values of given array
    {
        arr = new T[X];
        for(int i=0;i<Y;i++)
            arr[i] = data[i];
        top = Y;
        capacity = X;
    }
    ~MyStack()
    {
        delete [] arr;
    }
    int length()  // O(1)
    {
        return top;
    }
    void push(T item)  // O(n)
    {
        if(top==capacity)
        {
            expand();
        }
        arr[top++] = item;
    }
    T pop()
    {
        if(top==0)  // Empty Stack
        {
            cout<<"Cannot pop from empty stack\n";
            T dummy;
            return dummy;
        }
        T ans = arr[--top];
        if(top <= capacity/2)
        {
            shrink();
        }
        return ans;
    }
    T topValue()
    {
        if(top==0)  // Empty Stack
        {
            cout<<"Stack is Empty\n";
            T dummy;
            return dummy;
        }
        return arr[top-1];
    }
    void clear()
    {
        if(arr)
            delete [] arr;
        arr = new T[1];
        top = 0;
        capacity = 1;
    }
    void print()
    {
        cout<<"Stack : ";
        if(top==0)
        {
            cout<<"<>\n";
            return;
        }
        cout<<"<";
        for(int i=0;i<top-1;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"|";
        cout<<" "<<arr[top-1];
        cout<<">\n";
    }

};
