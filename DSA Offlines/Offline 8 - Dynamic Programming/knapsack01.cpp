#include<bits/stdc++.h>
using namespace std;

#define UP 0
#define DIAGONAL 1
#define BOTH 2

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,W;
    cin>>n;
    int value[n+1],weight[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>weight[i]>>value[i];
        if(weight[i]<0)
        {
            cout<<"Sorry, Weight cannot be negative."<<endl;
        }
    }
    cin>>W;

    int dp[n+1][W+1],action[n+1][W+1];
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    for(int j=0;j<=W;j++)
        dp[0][j] = 0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(weight[i]>j)
            {
                dp[i][j] = dp[i-1][j];
                action[i][j] = UP;
            }
            else
            {
                int p = dp[i-1][j];
                int q = value[i]+dp[i-1][j-weight[i]];
                if(p>q)
                {
                    action[i][j] = UP;
                }
                else if(p<q)
                {
                    action[i][j] = DIAGONAL;
                }
                else
                {
                    action[i][j] = BOTH;
                }
                dp[i][j] = max(p,q);
            }
        }
    }

    int maxGain = dp[n][W];
    cout<<maxGain<<endl;

    vector<int>taken;
    int i = n;
    int j = W;
    while(i>0 && j>0)
    {
        if(action[i][j]==UP || action[i][j]==BOTH)
        {
            i--;
        }
        else
        {
            taken.push_back(i);
            j = j - weight[i];
            i--;
        }
    }
    sort(taken.begin(),taken.end());
    for(int x: taken)
    {
        cout<<weight[x]<<" ";
    }
    cout<<endl;

}

/*

4
20 40
10 100
40 50
30 60
60

Ans:

200
20 10 30

*/
