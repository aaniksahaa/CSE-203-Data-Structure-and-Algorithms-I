#include<bits/stdc++.h>
using namespace std;

struct Job{
    int profit, deadline, id;
    void show()
    {
        cout<<"Id : "<<id<<" - [ "<<profit<<" , "<<deadline<<" ]\n";
    }
};

bool cmp_profit(Job a, Job b)
{
    return (a.profit < b.profit);
}

int main()
{
    int n,mx=-1,total=0;
    cout<<"Enter the number of jobs: ";
    cin>>n;

    vector<Job>jobs;

    cout<<"\nEnter profit and deadline of jobs: \n\n";
    for(int i=0;i<n;i++)
    {
        int p,d;
        printf(" %2d.  ",i+1);
        //cout<<" "<<i+1<<".  ";
        cin>>p>>d;

        mx = max(mx,d);

        jobs.push_back({p,d,i+1});

    }

    //O(n^2) Naive

    int sch[mx+1];
    for(int i=0;i<=mx;i++)
    {
        sch[i] = -1;
    }

    sort(jobs.rbegin(),jobs.rend(),cmp_profit);

    for(Job j: jobs)
    {
        int d = j.deadline;
        int last_blank;

        for(int i=d;i>=1;i--)
        {
            if(sch[i]==-1)
            {
                sch[i] = j.id;
                total += j.profit;
                break;
            }
        }
    }
    cout<<"\nOptimal Selection:\n\n";
    for(int i=1;i<=mx;i++)
    {
        if(i>1)
            cout<<" , ";
        if(sch[i]==-1)
        {
            cout<<"___";
        }
        else
        {
            cout<<" "<<sch[i]<<" ";
        }
    }
    cout<<endl;
    cout<<"\nMaximum total profit: "<<total<<endl<<endl;

}

/* 2017-18-2(a)

13
7 5
6 5
5 2
4 7
3 7
3 7
3 6
2 7
2 1
2 5
2 3
2 1
1 1

*/

/* 2019-20-1(b)

10
9 7
14 3
5 2
10 6
3 8
15 5
5 6
7 3
8 2
6 4

*/

