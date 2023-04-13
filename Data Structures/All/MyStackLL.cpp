#include<bits/stdc++.h>
using namespace std;

/*
template<class T>
class Node{
public:
    T value;
    Node *left, *right;
    Node()
    {
        left = right = NULL;
    }
    Node(T val, Node *l = NULL, Node *r = NULL)
    {
        value = val;
        left = l;
        right = r;
    }
};
*/

template<class T>
class MyStack{

    Node<T>*top;  // points to the first element
    int len;

    void init()
    {
        top = NULL;  // Empty List
        len = 0;
    }
    void pushFirst(T item)  // Pushing the first element
    {
        Node<T>* node = new Node<T>(item,NULL,NULL);
        top = node;
    }

public:

    MyStack(int X=1)  // Default constructor
    {
        init();
    }
    ~MyStack()  // Destructor
    {
        while(len>0)
        {
            Node<T>*temp = top->right;
            delete top;
            top = temp;
            len--;
        }
    }
    int length()
    {
        return len;
    }
    void push(T item)
    {
        if(len == 0)  // Inserting first element
        {
            pushFirst(item);
        }
        else
        {
            Node<T>* node = new Node<T>(item,NULL,top);
            top->left = node;
            top = node;
        }
        len++;
    }
    T pop()
    {
        if(len==0)
        {
            cout<<"Cannot pop from empty stack\n";
            T dummy;
            return dummy;
        }
        else if(len==1)
        {
            T ans = top->value;
            top = NULL;
            len = 0;
            return ans;
        }
        else
        {
            T ans = top->value;
            Node<T>*temp = top;
            top = top->right;
            top->left = NULL;
            delete temp;
            len--;
            return ans;
        }
    }
    T topValue()
    {
        if(len==0)
        {
            cout<<"Stack is Empty\n";
            T dummy;
            return dummy;
        }
        return top->value;
    }
    void clear()
    {
        while(len>0)
        {
            Node<T>*temp = top->right;
            delete top;
            top = temp;
            len--;
        }
        init();
    }
    void print()
    {
        cout<<"Stack : ";
        if(len==0)
        {
            cout<<"<>\n";
            return;
        }
        Node<T>* node = top;
        T *narr = new T[len];
        cout<<"<";
        int i = len-1;
        while(node != NULL)
        {
            narr[i] = node->value;
            node = node->right;
            i--;
        }
        for(int i=0;i<len-1;i++)
        {
            cout<<narr[i]<<" ";
        }
        cout<<"| ";
        cout<<top->value;
        cout<<">\n";

    }

};
