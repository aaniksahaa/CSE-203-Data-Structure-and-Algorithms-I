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
    Node(T val, Node* l = NULL, Node *r = NULL)
    {
        value = val;
        left = l;
        right = r;
    }
};

template<class T>
class MyList{

    Node<T> *head, *tail, *curr;
    int len;

    void init()
    {
        head = tail = curr = NULL;  // Empty List
        len = 0;
    }
    void initHeadTail(T item)  // Inserting the first element
    {
        Node<T>* node = new Node<T>(item,NULL,NULL);
        curr = node;
        head = tail = node;
    }



public:

    MyList()  // Default constructor
    {
        init();
    }
    ~MyList()  // Destructor
    {

    }
    int size()
    {
        return len;
    }
    void push(T item)
    {
        if(len == 0)  // Inserting first element
        {
            initHeadTail(item);
        }
        else if(curr == head)  // Inserting new head
        {
            Node<T>* node = new Node<T>(item,NULL,head);
            head->left = node;
            head = node;
            curr = node;
        }
        else
        {
            Node<T>* node = new Node<T>(item,curr->left,curr);
            curr->left->right = node;
            curr->left = node;
            curr = node;
        }
        len++;
    }
    void pushBack(T item)
    {
        if(len == 0)
        {
            initHeadTail(item);
        }
        else
        {
            Node<T>* node = new Node<T>(item,tail,NULL);
            tail->right = node;
            tail = node;
        }
        len++;
    }
    T erase()
    {
        if(len == 0) // Already empty
        {
            T dummy;
            return dummy;
        }
        T ret = curr->value;
        if(len == 1)  // List will become empty
        {
            delete head;
            head = tail = curr = NULL;
        }
        else if(curr == head)
        {
            Node<T>* node = head;
            head->right->left = NULL;
            head = head->right;
            curr = head;
            delete node;
        }
        else if(curr == tail)
        {
            Node<T>* node = tail;
            tail->left->right = NULL;
            tail = tail->left;
            curr = tail;
            delete node;
        }
        else
        {
            Node<T>* node = curr;
            curr->left->right = curr->right;
            curr->right->left = curr->left;
            curr = curr->right;
            delete node;
        }
        len--;
        return ret;
    }
    void setToBegin()
    {
        curr = head;
    }
    void setToEnd()
    {
        curr = tail;
    }
    void prev()
    {
        if(len>0 && curr != head)
        {
            curr = curr->left;
        }
    }
    void next()
    {
        if(len>0 && curr!= tail)
        {
            curr = curr->right;
        }
    }
    int currPos()
    {
        Node<T>*node = head;
        int i = 0;
        while(node != curr)
        {
            node = node->right;
            i++;
        }
        return i;
    }
    void setToPos(int pos)
    {
        if(pos>=0 && pos<len)
        {
            Node<T>*node = head;
            for(int i=0;i<pos;i++)
            {
                node = node->right;
            }
            curr = node;
        }
        else
            cout<<"Position out of range\n";
    }
    T getValue()
    {
        if(len==0)
        {
            T dummy;
            return dummy;
        }
        return curr->value;
    }
    int find(T item)
    {
        int found = -1;
        Node<T>*node = head;
        for(int i=0;i<len;i++)
        {
            if(node->value == item)
            {
                found = i;
                break;
            }
            node = node->right;
        }
        return found;
    }
    void clear()
    {
        setToEnd();
        while(len>0)
        {
            erase();
        }
        init();
    }
    void print()
    {
        if(len==0)
        {
            cout<<"<>\n";
            return;
        }
        Node<T>* node = head;
        cout<<"<";
        while(node != curr)
        {
            cout<<node->value<<" ";
            node = node->right;
        }
        cout<<"| ";
        while(node != tail)
        {
            cout<<node->value<<" ";
            node = node->right;
        }
        cout<<tail->value;
        cout<<">\n";

    }

};
