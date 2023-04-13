#include<bits/stdc++.h>
using namespace std;

template<class T>
class Queue{
public:

    stack<T> s1,s2;

    Queue()
    {

    }
    void enqueue(T item)
    {
        s1.push(item);
    }
    T dequeue()
    {
        if(s1.empty())
        {
            cout<<"Sorry, Queue empty.\n";
            return -222;
        }
        T ret;
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        ret = s2.top();
        s2.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ret;
    }
};

int main()
{
    Queue<int>Q;

    while(1)
    {
        int p;

        string str;
        cin>>str;

        if(str == "enq")
        {
            cin>>p;
            Q.enqueue(p);
        }
        else
        {
            int ans = Q.dequeue();
            if(ans != -222)
                cout<<ans<<endl;
        }
    }
}
