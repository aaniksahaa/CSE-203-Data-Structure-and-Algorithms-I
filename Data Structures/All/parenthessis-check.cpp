#include<bits/stdc++.h>
using namespace std;

bool check(string str)
{
    stack<char>s;
    for(char ch: str)
    {
        if(ch == '(')
        {
            s.push(')');
        }
        else
        {
            if(s.empty())
                return false;
            else
            {
                s.pop();
            }
        }
    }

    if(s.empty())
        return true;
    return false;
}
int offend(string str)
{
    int n = str.length();
    stack<int>s;

    for(int pos=0;pos<n;pos++)
    {
        if(str[pos] == '(')
        {
            s.push(pos);
        }
        else
        {
            if(s.empty())
            {
                return pos;
            }
            else
                s.pop();
        }
    }
    if(s.empty())
        return -1;
    return s.top();
}
int main()
{
    while(1)
    {
        string s;
        cin>>s;
        cout<<offend(s)<<endl;
    }
    return 0;
}
