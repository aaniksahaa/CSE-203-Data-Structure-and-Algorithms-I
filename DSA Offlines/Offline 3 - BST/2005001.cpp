#include<bits/stdc++.h>
using namespace std;

template<class T>
class Bnode{
public:
    T value;
    Bnode<T>*left;
    Bnode<T>*right;
    Bnode(T item, Bnode<T>*l = NULL, Bnode<T>*r = NULL)
    {
        value = item;
        left = l;
        right = r;
    }
};

template<class T>
class BST{

    Bnode<T>*rt;   // Pointer to the root
    int nodeCount;

    Bnode<T>*insertHelp(Bnode<T>*root, T item)
    {
        if(root == NULL)
        {
            root = new Bnode<T>(item);
            nodeCount++;
        }
        else if(item > root->value)
        {
            root->right = insertHelp(root->right,item);
        }
        else if(item < root->value)
        {
            root->left = insertHelp(root->left,item);
        }
        else
        {
            cout<<"Duplicate node not allowed.\n";
        }
        return root;
    }
    bool findHelp(Bnode<T>*root, T item)
    {
        if(root==NULL)
        {
            return false;
        }
        else if(item > root->value)
        {
            return findHelp(root->right, item);
        }
        else if(item < root->value)
        {
            return findHelp(root->left,item);
        }
        else
        {
            return true;
        }
    }
    Bnode<T>*delHelp(Bnode<T>*root, T item)
    {
        if(root==NULL)
        {
            return NULL;
        }
        else if(item > root->value)
        {
            root->right = delHelp(root->right, item);
        }
        else if(item < root->value)
        {
            root->left = delHelp(root->left,item);
        }
        else
        {
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                nodeCount--;
                return NULL;
            }
            else
            {
                // So this is not a leaf
            }
        }
        return root;
    }
    void preHelp(Bnode<T>*root)
    {
        if(root == NULL)
            return;
        cout<<root->value<<" ";
        preHelp(root->left);
        preHelp(root->right);
    }
    void postHelp(Bnode<T>*root)
    {
        if(root == NULL)
            return;
        postHelp(root->left);
        postHelp(root->right);
        cout<<root->value<<" ";
    }
    void inHelp(Bnode<T>*root)
    {
        if(root == NULL)
            return;
        inHelp(root->left);
        cout<<root->value<<" ";
        inHelp(root->right);
    }
    void printHelp(Bnode<T>*root)
    {
        if(root == NULL)
            return;
        cout<<root->value;
        if(root->left == NULL && root->right == NULL)
        {
            return;
        }
        cout<<"(";
        printHelp(root->left);
        cout<<")(";
        printHelp(root->right);
        cout<<")";
    }
public:

    BST()
    {
        rt = NULL;
        nodeCount = 0;

    }
    void insert(T item)
    {
        rt = insertHelp(rt,item);
        nodeCount++;
        print();
    }
    bool find(T item)
    {
        return findHelp(rt,item);
    }
    void del(T item)
    {
        if(!find(item))
        {
            cout<<"Invalid Operation\n";
            return;
        }
        int n = nodeCount;
        rt = delHelp(rt,item);
        if(nodeCount<n)
        {
            print();
        }
        else
        {
            cout<<"Invalid Operation\n";
            return;
        }
    }
    void preOrder()
    {
        preHelp(rt);
        cout<<"\n";
    }
    void postOrder()
    {
        postHelp(rt);
        cout<<"\n";
    }
    void inOrder()
    {
        inHelp(rt);
        cout<<"\n";
    }
    void print()
    {
        printHelp(rt);
        cout<<"\n";
    }

};

int main()
{
    //freopen("input.txt", "r", stdin);
    freopen("out6.txt", "w", stdout);
    BST<int>b;
    char ch;
    while(cin>>ch)
    {
        int p;
        if(ch == 'I')
        {
            cin>>p;
            b.insert(p);
        }
        else if(ch == 'F')
        {
            cin>>p;
            bool bb = b.find(p);
            if(bb)
            {
                cout<<"True\n";
            }
            else
            {
                cout<<"False\n";
            }
        }
        else if(ch == 'D')
        {
            cin>>p;
            b.del(p);
        }
        else if(ch == 'T')
        {
            string s;
            cin>>s;
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            if(!s.compare("pre"))
            {
                b.preOrder();
            }
            else if(!s.compare("post"))
            {
                b.postOrder();
            }
            else if(!s.compare("in"))
            {
                b.inOrder();
            }
            else
            {
                cout<<"Invalid input\n";
            }

        }
    }
    return 0;
}

/*


I 10
I 11
F 6
I 6
F 6
I 4
F 11
I 17
I 8
I 7
I 21
I 9
T In
T Pre
T Post
F 9
D 9
F 9
D 11
F 11


*/
