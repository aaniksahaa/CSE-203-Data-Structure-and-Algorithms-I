#include<bits/stdc++.h>
using namespace std;

template<class T>
class MyList{

    T * arr;
    int curr,len,capacity;

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
    void rightShift()
    {
        for(int i=len-1;i>=curr;i--)
        {
            arr[i+1] = arr[i];
        }
    }

public:
    MyList(int X = 1)  // given capacity
    {
        arr = new T[X];
        len = 0;
        capacity = X;
        curr = 0;
    }
    MyList(int X, int Y)  // given capacity and length
    {
        arr = new T[X];
        for(int i=0;i<Y;i++)
            arr[i] = 0;     // default initialize with zero
        len = Y;
        capacity = X;
        curr = 0;
    }
    MyList(int X, int Y, T *data)  // Initialize with the values of given array
    {
        arr = new T[X];
        for(int i=0;i<Y;i++)
            arr[i] = data[i];
        len = Y;
        capacity = X;
        curr = 0;
    }
    ~MyList()
    {
        delete [] arr;
    }
    int size()  // O(1)
    {
        return len;
    }
    void push(T item)  // O(n)
    {
        if(len==capacity)
        {
            expand();
        }
        rightShift();
        arr[curr] = item;
        len++;
    }
    void pushBack(T item)  // O(1)
    {
        if(len==capacity)
        {
            expand();
        }
        arr[len] = item;
        len++;
    }
    T erase()    // O(n)
    {
        if(len == 0)  // Already empty
        {
            T dummy;
            return dummy;
        }
        T ret = arr[curr];
        if(len!=1 && curr == len-1)
        {
            curr--;  // Set curr to new last element
        }
        else
        {
            for(int i=curr;i<len-1;i++)
            {
                arr[i] = arr[i+1];
            }
        }
        len--;
        if(len <= capacity/2)
        {
            shrink();
        }
        return ret;
    }
    void setToBegin()  // O(1)
    {
        curr = 0;
    }
    void setToEnd()   // O(1)
    {
        curr = len-1;
    }
    void prev()  // O(1)
    {
        if(curr != 0)
            curr--;
    }
    void next()  // O(1)
    {
        if(curr != len-1)
            curr++;
    }
    int currPos()  // O(1)
    {
        return curr;
    }
    void setToPos(int pos)  // O(1)
    {
        if(pos>=0 && pos<len)
            curr = pos;
        else
            cout<<"Position out of range\n";
    }
    T getValue()  // O(1)
    {
        if(len==0)
        {
            T dummy;
            return dummy;
        }
        return arr[curr];
    }
    int find(T item)  // O(n)
    {
        int found = -1;
        for(int i=0;i<len;i++)
        {
            if(arr[i] == item)
            {
                found = i;
                break;
            }
        }
        return found;
    }
    void clear()
    {
        if(arr)
            delete [] arr;
        arr = new T[1];
        len = 0;
        capacity = 1;
        curr = 0;
    }
    void print()
    {
        if(len==0)
        {
            cout<<"<>\n";
            return;
        }
        cout<<"<";
        for(int i=0;i<curr;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"|";
        for(int i=curr;i<len;i++)
        {
            cout<<" "<<arr[i];
        }
        cout<<">\n";
    }

};
