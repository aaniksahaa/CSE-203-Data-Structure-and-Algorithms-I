#include<bits/stdc++.h>
using namespace std;

struct Job{
    int start, finish, id;
    void show()
    {
        cout<<"Id : "<<id<<" - [ "<<start<<" , "<<finish<<" ]\n";
    }
};

bool cmp_finish(Job a, Job b)
{
    return (a.finish < b.finish);
}

bool cmp_start(Job a, Job b)
{
    return (a.start < b.start);
}

bool cmp_interval(Job a, Job b)
{
    return ((a.finish-a.start)<(b.finish-b.start));
}

bool collide(Job a, Job b)
{
    if((b.start>=a.finish) || (a.start>=b.finish))
        return 0;
    return 1;
}

int main()
{
    int n;
    cout<<"Enter the number of jobs: ";
    cin>>n;

    vector<Job>jobs;

    cout<<"\nEnter start and finish times of jobs: \n\n";
    for(int i=0;i<n;i++)
    {
        int s,f;
        cout<<" "<<i+1<<".  ";
        cin>>s>>f;

        jobs.push_back({s,f,i+1});

    }

    sort(jobs.begin(),jobs.end(),cmp_finish);

    vector<Job>taken;

    //optimal

    cout<<"\nOptimal Solution: \n\n";

    taken.clear();

    int lastfinished = -1;

    for(Job j: jobs)
    {
        if(j.start >= lastfinished)
        {
            taken.push_back(j);
            lastfinished = j.finish;
        }
    }

    for(Job j: taken)
    {
        j.show();
    }

    //earliest finishing time

    sort(jobs.begin(),jobs.end(),cmp_finish);

    cout<<"\nBy Earliest Finishing Time: \n\n";

    taken.clear();

    lastfinished = -1;

    for(Job j: jobs)
    {
        if(j.start >= lastfinished)
        {
            taken.push_back(j);
            lastfinished = j.finish;
        }
    }

    for(Job j: taken)
    {
        j.show();
    }

    //earliest starting time

    sort(jobs.begin(),jobs.end(),cmp_start);

    cout<<"\nBy Earliest Starting Time: \n\n";

    taken.clear();

    lastfinished = -1;

    for(Job j: jobs)
    {
        if(j.start >= lastfinished)
        {
            taken.push_back(j);
            lastfinished = j.finish;
        }
    }

    for(Job j: taken)
    {
        j.show();
    }

    //shortest interval

    sort(jobs.begin(),jobs.end(),cmp_interval);

    cout<<"\nBy Shortest Interval: \n\n";

    taken.clear();

    for(Job j: jobs)
    {
        int ok = 1;
        for(Job p: taken)
        {
            if(collide(j,p))
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            taken.push_back(j);
        }
    }

    for(Job j: taken)
    {
        j.show();
    }

    return 0;
}

/* 2018-19-2(b)

7
1 6
4 8
6 8
9 15
6 9
11 15
2 6

*/
