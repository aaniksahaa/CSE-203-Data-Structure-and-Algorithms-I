#include<bits/stdc++.h>
#define inf 1e18
using namespace std;

struct Matrix{
    int row,col,id;
    Matrix(int r=0, int c=0, int i=0)
    {
        row = r;
        col = c;
        id = i;
    }
};

int main()
{
    int n;

    cout<<"Enter the number of matrices: ";
    cin>>n;

    Matrix mat[n+1];

    cout<<"\nEnter rows and columns of the matrices: \n\n";
    for(int i=1;i<=n;i++)
    {
        cout<<"  "<<i<<". ";
        int r,c;
        cin>>r>>c;
        mat[i] = Matrix(r,c,i);
    }

    int dp[n+1][n+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j] = -1;
        }
    }

    for(int i=1;i<=n;i++)
    {
        dp[i][i] = 0;
    }

    for(int diff=1;diff<n;diff++)
    {
        for(int i=1;(i+diff)<=n;i++)
        {
            int cost = inf;
            int j = i+diff;
            for(int k=i;k<j;k++)
            {
                cost = min(cost,dp[i][k] + dp[k+1][j] + (mat[i].row * mat[k].col * mat[j].col));
            }
            dp[i][j] = cost;
        }
    }

    cout<<"\nDP Table: \n\n";

    for(int i=1;i<=n;i++)
    {
        cout<<"   ";
        for(int j=1;j<=n;j++)
        {
            printf("%-6d ",dp[i][j]);
        }
        cout<<endl<<endl;
    }

    return 0;
}


/* 2020-21-6(a)

6
30 35
35 15
15 5
5 10
10 20
20 25

*/

/* 2018-19-2(c)

6
1 4
4 5
5 3
3 6
6 7
7 1

*/
