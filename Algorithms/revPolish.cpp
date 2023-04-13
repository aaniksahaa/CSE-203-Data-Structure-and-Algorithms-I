#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cout<<"Enter expression in reverse-polish: \n\n";
    cin>>a;
    stack<int>s;

    int n = a.length();

    for(int i=0;i<n;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            s.push(a[i]-'0');
        }
        else
        {
            if(s.size()<2)
            {
                cout<<"Expression invalid.\n";
                break;
            }
            else
            {
                int p,q;
                p = s.top();
                s.pop();
                q = s.top();
                s.pop();
                swap(p,q);
                int ans;
                if(a[i]=='+')
                {
                    ans = p+q;
                }
                else if(a[i]=='-')
                {
                    ans = p-q;
                }
                else if(a[i]=='x')
                {
                    ans = p*q;
                }
                else if(a[i]=='/')
                {
                    if(q==0)
                    {
                        cout<<"Division by Zero error.\n";
                        break;
                    }
                    ans = p/q;
                }
                s.push(ans);

            }
        }
    }
    if(s.size()!=1)
    {
        cout<<"Expression invalid.\n";
    }
    else
    {
        cout<<"\nResult = "<<s.top()<<endl;
    }
}
