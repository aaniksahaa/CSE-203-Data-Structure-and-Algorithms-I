#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cout<<"\nEnter the length of rod: ";
    cin>>n;

    int a[n+1],dp[n+1];
    cout<<"\nEnter the prices of rod pieces: \n\n";
    a[0] = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[0] = 0;
    for(int i=1;i<=n;i++)
    {
        dp[i] = INT_MIN;
        for(int j=i-1;j>=0;j--)
        {
            dp[i] = max(dp[i] , a[i-j]+dp[j]);
        }
    }

    cout<<"\n\nMaximum Profit : "<<dp[n]<<endl;
    return 0;
}

/* Cormen

10
1 5 8 9 10 17 17 20 24 30

*/

