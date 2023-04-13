#include<bits/stdc++.h>
using namespace std;

#define inf 1000000

template<class T>
class QueueC{
    int front,rear,capacity;
    T*arr;
    void expand()
    {
        int newcapacity;
        if(capacity==0)
        {
            newcapacity = 1;
        }
        else
        {
            newcapacity = 2*capacity;
        }
        T*newarr = new T[newcapacity];
        int j = 1;
        int i;
        for(i=front;i!=rear;i++)
        {
            newarr[j] = arr[i];
            i = (i+1)%capacity;
            j++;
        }
        newarr[j] = arr[i];
        rear = j;
        front = 1;
        capacity = newcapacity;
        if(arr)
            delete arr;
        arr = newarr;
    }
public:
    QueueC(int c = 10)
    {
        capacity = c+1;
        arr = new T[capacity];
        front = 1;
        rear = 0;
        for(int i=0;i<capacity;i++)
            arr[i] = -inf;
    }
    void enqueue(T item)
    {
        if(length()==capacity-1)
        {
            cout<<"Queue is full\n";
            return;
        }
        rear = (rear+1)%capacity;
        arr[rear] = item;
    }
    T dequeue()
    {
        if(length()==0)
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        T ret = arr[front];
        arr[front] = -inf;
        front = (front+1)%capacity;
        return ret;
    }
    T frontVal()
    {
        return arr[front];
    }
    T rearVal()
    {
        return arr[rear];
    }
    int length()
    {
        return (rear-front+1+capacity)%capacity;
    }
    void printArray()
    {
        cout<<"[ ";
        for(int i=0;i<capacity-1;i++)
        {
            if(arr[i]==-inf)
            {
                cout<<"_";
            }
            else
            {
                cout<<arr[i];
            }
            cout<<" | ";
        }
        if(arr[capacity-1]==-inf)
        {
            cout<<"_";
        }
        else
        {
            cout<<arr[capacity-1];
        }
        cout<<" ]"<<endl;
    }
};

int main()
{
    int cap;
    cout<<"Enter capacity of queue: ";
    cin>>cap;
    QueueC<int> Q(cap);
    string choice;
    while(1)
    {
        cin>>choice;
        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
        if(choice=="enq")
        {
            int p;
            cin>>p;
            Q.enqueue(p);
        }
        if(choice=="deq")
        {
            cout<<Q.dequeue()<<endl;
        }
        if(choice=="len")
        {
            cout<<Q.length()<<endl;
        }
        if(choice=="front")
        {
            cout<<Q.frontVal()<<endl;
        }
        if(choice=="len")
        {
            cout<<Q.rearVal()<<endl;
        }
        cout<<endl;
        Q.printArray();
        cout<<endl;
    }
}
