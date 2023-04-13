#include<bits/stdc++.h>
#include "Node.cpp"
#include "MyQueueLL.cpp"
//#include "MyQueueArr.cpp"
//#include "MyStackLL.cpp"
#include "MyStackArr.cpp"
using namespace std;

struct player{
    int id, arrive, start, duration;
    player(int i = -1, int s = -1, int d = -1)
    {
        id = i;
        arrive = s;
        start = -1;
        duration = d;
    }
    void init()
    {
        id = arrive = start = duration = -1;
    }
    bool operator<(player p)
    {
        return arrive < p.arrive;  // to sort as per arrival time
    }
    void print()
    {
        cout<<"Player "<<id<<" : Arrive = "<<arrive<<" , Start = "<<start<<" , Duration = "<<duration<<"\n";
    }
    bool empty()
    {
        return (id==-1);
    }
    bool started()
    {
        return !(start==-1);
    }
};

int main()
{

    freopen("fifa_input.txt", "r", stdin);
    freopen("fifa_output.txt", "w", stdout);

    player A,B;  // denotes the players consoles
    player p[1000];
    MyQueue<player>Q;
    MyStack<player>S;
    int s,d;
    A.init();
    B.init();

    int n,c;
    int processed = 0;
    cin>>n>>c;
    int ans[n+1];
    for(int i=0;i<n+1;i++)
    {
        ans[i] = -1;
    }

    for(int i=0;i<n;i++)
    {
        cin>>s>>d;
        p[i] = player(i+1,s,d);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[j]<p[i])
            {
                swap(p[i],p[j]);
            }
        }
    }

    for(int t=0;t<=c;t++)  // Simulate through time
    {
        //cout<<"Time = "<<t<<"\n";
        if((!A.empty()) && ((t-A.start) == A.duration))
        {
            //cout<<A.id<<" leaves A\n";
            ans[A.id] = t;
            A.init();
        }
        if((!B.empty()) && ((t-B.start) == B.duration))
        {
            //cout<<B.id<<" leaves B\n";
            ans[B.id] = t;
            B.init();
        }
        while((A.empty()) && Q.length()>0)
        {
            A = Q.dequeue();
            A.start = t;
            //cout<<A.id<<" enters A\n";
            //A.print();
            if(A.duration==0)
            {
                ans[A.id] = t;
                A.init();
            }
        }
        while(processed<n && (p[processed].arrive==t))
        {
            player pp = p[processed];
            //cout<<pp.id<<" arrives\n";
            if(A.empty())
            {
                A = pp;
                A.start = t;
                //cout<<A.id<<" enters A\n";
                //A.print();
                if(A.duration==0)
                {
                    ans[A.id] = t;
                    A.init();
                }
            }
            else
            {
                if(Q.length()<3)
                {
                    Q.enqueue(pp);
                    //cout<<pp.id<<" stands in queue\n";
                }
                else
                {
                    S.push(pp);
                    //cout<<pp.id<<" stands in stack\n";
                }
            }
            processed++;
        }
        while((B.empty()) && S.length()>0)
        {
            B = S.pop();
            //B.print();
            B.start = t;
            //cout<<B.id<<" enters B\n";
            if(B.duration==0)
            {
                ans[B.id] = t;
                B.init();
            }
        }
    }

    if(!A.empty())
    {
        ans[A.id] = c;
        A.init();
    }
    if(!B.empty())
    {
        ans[B.id] = c;
        B.init();
    }
    while(Q.length()>0)
    {
        player pp = Q.dequeue();
        ans[pp.id] = c;
    }
    while(S.length()>0)
    {
        player pp = S.pop();
        ans[pp.id] = c;
    }

    for(int i=1;i<=n;i++)
    {
        cout<<i<<">"<<ans[i]<<"\n";
    }
}

/*

9 90
12 14
17 11
23 18
25 11
29 8
34 6
36 8
38 9
40 8

*/

/*

8 60
2 12
3 13
6 14
8 11
10 11
15 10
16 8
20 13

*/
