#include<bits/stdc++.h>
using namespace std;

#define inf 1000000

template<class T>
class OATS{
    T*arr;
    int len1,len2,top1,top2,capacity;
    int choice;
public:
    OATS(int c=10)
    {
        capacity = c;
        choice = 1;
        arr = new T[capacity];
        top1 = 0;
        top2 = capacity-1;
        len1 = len2 = 0;

        for(int i=0;i<capacity;i++)
            arr[i] = -inf;
    }
    void chooseStack(int p) // 1 or 2
    {
        choice = p;
    }
    void push(int item)
    {
        if(len1+len2 == capacity)
        {
            cout<<"OATS is full\n";
            return;
        }
        if(choice==1)
        {
            arr[top1++] = item;
            len1++;
        }
        else
        {
            arr[top2--] = item;
            len2++;
        }
    }
    T pop()
    {
        if(choice==1)
        {
            if(len1==0)
            {
                cout<<"First stack empty\n";
                return -1;
            }
            else
            {
                T ret = arr[--top1];
                arr[top1] = -inf;
                len1--;
                return ret;
            }
        }
        else
        {
            if(len2==0)
            {
                cout<<"Second stack empty\n";
                return -1;
            }
            else
            {
                T ret = arr[++top2];
                arr[top2] = -inf;
                len2--;
                return ret;
            }
        }
    }
    int length()
    {
        if(choice==1)
        {
            return len1;
        }
        else
        {
            return len2;
        }
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
    cout<<"Enter capacity of One-array-two-stack: ";
    cin>>cap;
    OATS<int> S(cap);
    cout<<endl;
    S.printArray();
    cout<<endl;
    string choice;
    while(1)
    {
        cin>>choice;
        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
        if(choice=="choose")
        {
            int p;
            cin>>p;
            if(p==1 || p==2)
            {
                S.chooseStack(p);
                if(p==1)
                {
                    cout<<"First Stack Chosen\n";
                }
                else
                {
                    cout<<"Second Stack Chosen\n";
                }
            }
            else
            {
                cout<<"Invalid Choice\n";
            }
        }
        if(choice=="push")
        {
            int p;
            cin>>p;
            S.push(p);
        }
        if(choice=="pop")
        {
            cout<<S.pop()<<endl;
        }
        if(choice=="len")
        {
            cout<<S.length()<<endl;
        }
        cout<<endl;
        S.printArray();
        cout<<endl;
    }
    return 0;
}
