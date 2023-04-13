#include<bits/stdc++.h>
#define min3(a,b,c) min(min(a,b),c)
#define setBit(n,i) n = (n|(1<<i))
#define isSet(n,i) bool(n&(1<<i))

using namespace std;
const int N = 100, M = 100;
string a,b;
int dp[M+1][N+1],action[M+1][N+1]={0};

vector<string>paths;

void print(string path)
{
    string f,s;
    f = s = "";
    int i,j;
    i = j = 1;
    reverse(path.begin(),path.end());
    //cout<<path<<endl;
    for(char ch: path)
    {
        if(ch == 'i')
        {
            f += "-";
            s += b[j];
            j++;
        }
        else if(ch == 'd')
        {
            f += a[i];
            s += "-";
            i++;
        }
        else
        {
            f += a[i];
            s += b[j];
            i++;
            j++;
        }
    }
    cout<<endl<<"   "<<f<<endl;
    cout<<"   "<<s<<endl;
}

void explore(int i, int j, string path) //path = actions so far
{
    if((i==0) && (j==0))
    {
        paths.push_back(path);
        return;
    }
    int state = action[i][j];
    if(isSet(state,0))  //rep
    {
        string newpath = path + "r";
        explore(i-1,j-1,newpath);
    }
    if(isSet(state,1))  //ins
    {
        string newpath = path + "i";
        explore(i,j-1,newpath);
    }
    if(isSet(state,2))  //del
    {
        string newpath = path + "d";
        explore(i-1,j,newpath);
    }
}

int main()
{
    int ins,rep,del,m,n;

    cout<<"Enter the cost for insertion: ";
    cin>>ins;

    cout<<"Enter the cost for deletion: ";
    cin>>del;

    cout<<"Enter the cost for replacement: ";
    cin>>rep;

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
        dp[0][i] = i*ins;
        setBit(action[0][i],1);
    }
    for(int i=0;i<=m;i++)
    {
        dp[i][0] = i*del;
        setBit(action[i][0],2);
    }

    action[0][0] = 0;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int state = 0;
            int cost;
            int r;
            if(a[i]==b[j])
            {
                r = 0;
            }
            else
            {
                r = rep;
            }
            int u,v,w;
            u = dp[i-1][j-1]+r;
            v = dp[i][j-1]+ins;
            w = dp[i-1][j]+del;

            cost = min3(u,v,w);
            dp[i][j] = cost;

            if(cost == u)
            {
                setBit(state,0); // rep
            }
            if(cost == v)
            {
                setBit(state,1); // ins
            }
            if(cost == w)
            {
                setBit(state,2); // del
            }

            action[i][j] = state;
        }
    }

    cout<<"\nEdit distance = "<<dp[m][n]<<endl;

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
    cout<<"\nOptimal Matchings : "<<endl;
    for(string path: paths)
    {
        print(path);
    }

    return 0;
}

/*

2
2
1
PALETTE
PALATE

*/

/* 2019-20-1(a)
2
2
1
TGCATAT
ATCCGA

*/

/*2020-21-7(a)
1
1
1
ATTGCAT
TAGCCT
*/


