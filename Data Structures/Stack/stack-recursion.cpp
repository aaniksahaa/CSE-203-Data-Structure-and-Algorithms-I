#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
    stack<int>s;

    for(int i=n;i>=1;i--)
    {
        s.push(i);
    }
    int result = 1;
    while(!s.empty())
    {
        result *= s.top();
        s.pop();
    }

    return result;
}

int fib(int n)
{
    stack<int>s;
    s.push(n);
    int ans = 0;
    while(!s.empty())
    {
        int t = s.top();
        s.pop();
        if(t==1 || t==2)
        {
            ans += 1;
        }
        else
        {
            s.push(t-1);
            s.push(t-2);
        }
    }

    return ans;
}

int ceil(int n, int p)
{
    if(n%p==0)
        return n/p;
    return (n/p)+1;
}
int floor(int n, int p)
{
    return n/p;
}

int func(int n)
{
    if(n==1)
        return 1;
    return func(ceil(n,2))+func(floor(n,2))+n;
}
#define IN 1
#define OUT 2
class obj
{
public:
    int type;
    int val;

    obj(int t, int v)
    {
        type = t;
        val = v;
    }
};

int f(int n)
{
    stack<obj>s;
    s.push(obj(IN,n));
    int ans = 0;
    while(!s.empty())
    {
        obj t = s.top();
        s.pop();
        if(t.type == IN)
        {
            if(t.val == 1)
            {
                s.push(obj(OUT,1));
            }
            else
            {
                s.push(obj(IN,ceil(t.val,2)));
                s.push(obj(IN,floor(t.val,2)));
                s.push(obj(OUT,t.val));
            }
        }
        else
        {
            ans += t.val;
        }
    }

    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<f(n)<<endl;
    return 0;
}
