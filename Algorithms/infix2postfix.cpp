#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<char,int>precedence{ {'+',1} , {'-',1} , {'*',2} , {'/',2}};

    string a,ans;

    ans = "";

    cout<<"\nInput the string in infix notation: \n\n";
    cin>>a;

    stack<char>s;

    for(char ch: a)
    {
        if(ch == '(')
        {
            s.push('(');
        }
        else if(ch == ')')
        {
            while(!s.empty() && s.top()!='(')
            {
                ans += s.top();
                s.pop();
            }
            if(s.empty())
            {
                cout<<"\n\nSorry, there is extra right bracket.\n";
                break;
            }
            else
            {
                s.pop();
            }
        }
        else if(ch == '*' || ch == '+' || ch=='-' || ch == '/')
        {
            while(!s.empty())
            {
                char t = s.top();
                if( t == '(')
                    break;
                if(precedence[ch] <= precedence[t])
                {
                    s.pop();
                    ans += t;
                }
                else
                {
                    break;
                }
            }
            s.push(ch);
        }
        else if(ch == ' ')
        {

        }
        else
        {
            ans += ch;
        }
    }

    while(!s.empty())
    {
        ans += s.top();
        s.pop();
    }

    cout<<ans<<endl;

    return 0;
}
