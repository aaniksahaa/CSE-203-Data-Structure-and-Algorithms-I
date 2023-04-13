#include<bits/stdc++.h>
using namespace std;

template<class T>
class Node{
public:
    T value;
    Node *left, *right;
    Node()
    {
        left = right = NULL;
    }
    Node(T val, Node*l = NULL, Node *r = NULL)
    {
        value = val;
        left = l;
        right = r;
    }
};

template<class T>
class MyQueue{

    Node<T> *front, *rear;
    int len;

    void init()
    {
        front = rear = NULL;  // Empty List
        len = 0;
    }
    void enqueueFirst(T item)  // Inserting the first element
    {
        Node<T>* node = new Node<T>(item,NULL,NULL);
        front = rear = node;
    }

public:

    MyQueue(int X=1)  // Default constructor
    {
        init();
    }
    ~MyQueue()  // Destructor
    {
        while(len>0)
        {
            Node<T>*temp = front->right;
            delete front;
            front = temp;
            len--;
        }
    }
    int length()
    {
        return len;
    }
    void enqueue(T item)
    {
        if(len == 0)  // Inserting first element
        {
            enqueueFirst(item);
        }
        else
        {
            Node<T>* node = new Node<T>(item,rear,NULL);
            rear->right = node;
            rear = node;
        }
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
        else if(len==1)
        {
            T ans = rear->value;
            delete rear;
            init();
            return ans;
        }
        else
        {
            T ans = front->value;
            Node<T>*temp = front;
            front = front->right;
            front->left = NULL;
            delete temp;
            len--;
            return ans;
        }
    }
    T leaveQueue()
    {
        if(len==0)
        {
            cout<<"Cannot do leaveQueue from empty queue.\n";
            T dummy;
            return dummy;
        }
        T ans = rear->value;
        Node<T>*temp = rear;
        rear = rear->left;
        rear->right = NULL;
        delete temp;
        len--;
        return ans;
    }
    T frontValue()
    {
        if(len==0)
        {
            cout<<"Queue is Empty\n";
            T dummy;
            return dummy;
        }
        return front->value;
    }
    T rearValue()
    {
        if(len==0)
        {
            cout<<"Queue is Empty\n";
            T dummy;
            return dummy;
        }
        return rear->value;
    }
    void clear()
    {
        while(len>0)
        {
            Node<T>*temp = front->right;
            delete front;
            front = temp;
            len--;
        }
        init();
    }
    void print()
    {
        cout<<"Queue : ";
        if(len==0)
        {
            cout<<"<>\n";
            return;
        }
        Node<T>* node = front;
        cout<<"< | ";
        while(node != rear)
        {
            cout<<node->value<<" ";
            node = node->right;
        }
        cout<<rear->value;
        cout<<">\n";

    }

};
