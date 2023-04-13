#include<bits/stdc++.h>
#define min3(a,b,c) min(min(a,b),c)
#define setBit(n,i) n = (n|(1<<i))
#define isSet(n,i) bool(n&(1<<i))

using namespace std;
const int N = 100, M = 100;
string a,b;
int dp[M+1][N+1],action[M+1][N+1]={0};

set<string>paths;

void print(string path)
{
    reverse(path.begin(),path.end());
    cout<<path<<endl;
}

void explore(int i, int j, string path) //path = actions so far
{
    if((i==0) || (j==0))
    {
        reverse(path.begin(),path.end());
        paths.insert(path);
        return;
    }
    int state = action[i][j];
    if(isSet(state,0))  //diagonal
    {
        string newpath = path + a[i];
        explore(i-1,j-1,newpath);
    }
    if(isSet(state,1))  //up
    {
        string newpath = path ;
        explore(i-1,j,newpath);
    }
    if(isSet(state,2))  //left
    {
        string newpath = path ;
        explore(i,j-1,newpath);
    }
}

int main()
{
    int m,n;

    cout<<"\nEnter the first string: ";
    cin>>a;

    cout<<"\nEnter the second string: ";
    cin>>b;

    m = a.length();
    n = b.length();

    // making strings 1-indexed
    a = " " + a;
    b = " " + b;

    // dp[i][j] denotes longest common suffix between A[1..i] and B[1...j]

    for(int i=0;i<=n;i++)
    {
        dp[0][i] = 0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[i][0] = 0;
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    int ans = 0;

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            ans = max(ans,dp[i][j]);
        }
    }
    cout<<"\nLength of Longest Common Substring = "<<ans<<endl;

    cout<<"\nDP Table:\n\n";

    cout<<"        ";
    for(int i=0;i<=n;i++)
    {
        cout<<b[i]<<"    ";
    }
    cout<<endl<<endl;
    for(int i=0;i<=m;i++)
    {
        cout<<"   "<<a[i]<<"    ";
        for(int j=0;j<=n;j++)
        {
            printf("%-4d ",dp[i][j]);
            //cout<<dp[i][j]<<" ";
        }
        cout<<endl<<endl;
    }

    set<string>an;

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(dp[i][j] == ans)
            {
                an.insert(a.substr(i-ans+1,ans));
            }
        }
    }

    cout<<"\nLongest Common Substrings : "<<endl<<endl;
    int i = 1;
    for(string str: an)
    {
        cout<<" "<<i<<". "<<str<<endl;
        i++;
    }

    /*


    string tmp = "";
    explore(m,n,tmp);
    cout<<"\nLongest Common Subsequences : "<<endl<<endl;
    int i = 1;
    for(string path: paths)
    {
        cout<<" "<<i<<". "<<path<<endl;
        i++;
    }

    */


    return 0;
}

/*2017-18-(13)

buetcserocks
bdcserocks

*/



