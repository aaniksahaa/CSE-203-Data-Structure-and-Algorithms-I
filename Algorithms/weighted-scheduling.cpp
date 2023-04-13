#include<bits/stdc++.h>
using namespace std;

struct Job
{
	int start, finish, value;
	Job(int s, int f, int v)
	{
	    start = s;
	    finish = f;
	    value = v;
	}
};

bool operator<(Job s1, Job s2)
{
	return (s1.finish < s2.finish);
}

vector<Job>jobs;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int s,f,v;
        cin>>s>>f>>v;
        jobs.push_back(Job(s,f,v));
    }
    // sort by finish time
    sort(jobs.begin(),jobs.end());

    /*
    for(Job j: jobs)
    {
        cout<<j.start<<" "<<j.finish<<endl;
    }
    */


    int dp[n+1];

    dp[0] = jobs[0].value;

    for(int i=1;i<n;i++)
    {
        int nowStart = jobs[i].start;
        int ok = -1;
        for(int j=i-1;j>=0;j--)
        {
            if(jobs[j].finish <= nowStart)
            {
                ok = j;
                break;
            }
        }
        if(ok != -1)
        {
            dp[i] = max(dp[i-1],jobs[i].value + dp[ok]);
        }
        else
        {
            dp[i] = dp[i-1];
        }
    }

    cout<<dp[n-1]<<endl;

    return 0;
}

/*

4
1 2 50
3 5 20
6 19 100
2 100 200


*/
