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

    for(int i=0;i<=n;i++)
    {
        dp[0][i] = 0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[i][0] = 0;
    }

    action[0][0] = 0;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int state = 0;
            if(a[i]==b[j])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                setBit(state,0); // diagonal
            }
            else
            {
                int u,v;

                u = dp[i-1][j];  // up
                v = dp[i][j-1];  // left

                if(u>v)
                {
                    dp[i][j] = u;
                    setBit(state,1);  // up
                }
                else if(v>u)
                {
                    dp[i][j] = v;
                    setBit(state,2);  // left
                }
                else
                {
                    dp[i][j] = u;
                    setBit(state,1);  // up
                    setBit(state,2);  // left
                }
            }
            action[i][j] = state;
        }
    }

    cout<<"\nLength of Longest Common Subsequence = "<<dp[m][n]<<endl;

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

    /*
    cout<<"\nAction Table:\n\n";

    for(int i=0;i<=m;i++)
    {
        cout<<"   ";
        for(int j=0;j<=n;j++)
        {
            cout<<bitset<3>(action[i][j])<<" ";
            //printf("%-4d ",string(bitset<3>(action[i][j]))));
            //cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    string tmp = "";
    explore(m,n,tmp);
    cout<<"\nLongest Common Subsequences : "<<endl<<endl;
    int i = 1;
    for(string path: paths)
    {
        cout<<" "<<i<<". "<<path<<endl;
        i++;
    }


    return 0;
}

/* Slide

ABCBDAB
BDCABA

*/

/*2020-21-7(a)

ATTGCAT
TAGCCT

*/

/*2018-19-4(c)

TAAGUATU
AUAGTUT

*/



