#include<bits/stdc++.h>
using namespace std;

class customer{
public:
    int start,finish;
    customer()
    {
        start = finish = 0;
    }
    customer(int s, int f)
    {
        start = s;
        finish = f;
    }
};
bool operator<(customer p, customer q) // sort as per finishing time
{
    if(p.finish == q.finish)
    {
        return p.start < q.start;
    }
    else
    {
        return p.finish < q.finish;
    }
}

int main()
{
    int n,u,v,lastfinished=-1,cnt=0; // number of customers

    cin>>n;
    customer customers[n+5], served[n+5];

    for(int i=0;i<n;i++)
    {
        cin>>u>>v;
        customer c = customer(u,v);
        customers[i] = c;
    }

    sort(customers,customers+n);

    for(int i=0;i<n;i++)
    {
        u = customers[i].start;
        v = customers[i].finish;
        if(u >= lastfinished)   // this customer can be processed
        {
            served[cnt] = customers[i];
            cnt++;
            lastfinished = v;
        }
    }

    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
    {
        cout<<served[i].start<<" "<<served[i].finish<<endl;
    }

    return 0;
}
