#include<bits/stdc++.h>
#define setBit(n,i) n = (n|(1<<i))
#define isSet(n,i) bool(n&(1<<i))
using namespace std;

int n,W;
int dp[101][101],action[101][101];
int weight[101],value[101];
vector<vector<int>>solutions;

void explore(int i, int w, vector<int>taken) // taken = taken so far
{
    if(i==0 || w==0)
    {
        solutions.push_back(taken);
        return;
    }
    int state = action[i][w];
    if(isSet(state,0))  // up
    {
        explore(i-1,w,taken);
    }
    if(isSet(state,1))  // diagonal
    {
        auto newtaken = taken;
        newtaken.push_back(i);
        explore(i-1,w-weight[i],newtaken);
    }
}

int main()
{

    cout<<"Enter the number of objects: ";
    cin>>n;

    cout<<"\nEnter weights and values of objects: \n\n";
    for(int i=1;i<=n;i++)
    {
        cout<<" "<<i<<". ";
        int w,v;
        cin>>weight[i]>>value[i];
    }

    cout<<"\nEnter capacity: ";
    cin>>W;

    for(int i=0;i<=W;i++)
    {
        dp[0][i] = 0;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int w=1;w<=W;w++)
        {
            int state = 0;
            if(weight[i] > w)
            {
                dp[i][w] = dp[i-1][w];
                setBit(state,0); // up
            }
            else
            {

                int u = dp[i-1][w];
                int v = value[i] + dp[i-1][w-weight[i]];

                if(u>v)
                {
                    setBit(state,0);  // up
                    dp[i][w] = u;
                }
                else if(v>u)
                {
                    setBit(state,1);  // diagonal-taken
                    dp[i][w] = v;
                }
                else
                {
                    setBit(state,0);
                    setBit(state,1);
                    dp[i][w] = u;
                }
            }
            action[i][w] = state;
        }
    }

    cout<<"\nMaximum Profit = "<<dp[n][W]<<"\n\n";
    cout<<"DP Table: \n\n";

    for(int i=0;i<=n;i++)
    {
        cout<<"   ";
        for(int w=0;w<=W;w++)
        {
            printf("%-4d ",dp[i][w]);
        }
        cout<<endl<<endl;
    }

    /*
    cout<<"\nAction Table:\n\n";

    for(int i=0;i<=n;i++)
    {
        cout<<"   ";
        for(int j=0;j<=W;j++)
        {
            cout<<bitset<2>(action[i][j])<<" ";
        }
        cout<<endl;
    }
    */

    vector<int>vv;
    explore(n,W,vv);

    cout<<"\nOptimal Solutions: \n\n";
    int i=1;
    for(auto taken: solutions)
    {
        cout<<i<<". Items  =  ";
        sort(taken.begin(),taken.end());
        for(int j=0;j<taken.size()-1;j++)
        {
            cout<<taken[j]<<" , ";
        }
        cout<<taken[taken.size()-1]<<endl;
    }

    return 0;
}

/*2020-21-5(a)

4
3  15
2  20
10  30
2  14
6

*/

/*2018-19-1(c)

5
1  50
3  60
5  100
2  70
2  80
7

*/

/* 2017-18-(12)

5
2  7
1  8
2  12
2  6
2  10

*/


