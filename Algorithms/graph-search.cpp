#include<iostream>
#include "MyQueueArr.cpp"
//#include "MyQueueLL.cpp"

using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

const int inf = INT_MAX;
const int N = 1000;

int G[N+5][N+5];  // Adjacency Matrix
vector<int>adj[N+5];
int t;  // time
int vis[N+5],parent[N+5],dist[N+5],discover[N+5],finish[N+5],color[N+5];

vector<int>treeadj[N+5];  // Adjacency List for tree

void BFS(int src)
{
    int u;
    u = src;
    for(int i=0;i<=N;i++)
    {
        treeadj[i].clear();  // Clearing predecessor subgraph

        vis[i] = 0;
        parent[i] = -1;
        dist[i] = inf;
        color[i] = WHITE;
    }
    MyQueue<int>Q;
    Q.enqueue(src);
    dist[src] = 0;
    color[src] = GRAY;
    vis[src] = 1;
    while(Q.length() > 0)
    {
        u = Q.dequeue();
        //cout<<u<<endl;
        for(int v: adj[u])
        {
            if(color[v]==WHITE)
            {
                Q.enqueue(v);
                vis[v] = 1;
                color[v] = GRAY;
                parent[v] = u;
                dist[v] = dist[u]+1;

                treeadj[u].push_back(v); // storing tree edges
            }
        }
        color[u] = BLACK;
    }
}

void DFSrecurr(int s)
{
    //cout<<s<<endl;
    t++;
    vis[s] = 1;
    discover[s] = t;
    color[s] = GRAY;
    for(int v: adj[s])
    {
        if(color[v] == WHITE)
        {
            treeadj[s].push_back(v); // storing tree edges

            dist[v] = dist[s] + 1;
            parent[v] = s;
            DFSrecurr(v);
        }
    }
    color[s] = BLACK;
    t++;
    finish[s] = t;
}

void DFS(int src)
{
    t = 0;
    for(int i=0;i<=N;i++)
    {
        treeadj[i].clear();  // Clearing predecessor subgraph

        color[i] = WHITE;
        vis[i] = 0;
        parent[i] = -1;
        dist[i] = inf;
        discover[i]=-1;
        finish[i]=-1;
    }
    dist[src] = 0;
    DFSrecurr(src);
}

void printTreeAdjList(int n)
{
    for(int i=0;i<n;i++)
    {
        int m = treeadj[i].size();
        if(m==0)
            continue;
        cout<<i<<"->";
        for(int j=0;j<m-1;j++)
        {
            cout<<treeadj[i][j]<<",";
        }
        cout<<treeadj[i][m-1]<<endl;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,u,v,src;
    //out<<"Enter the number of vertices : ";
    cin>>n;
    //cout<<"Enter the number of edges : ";
    cin>>m;
    //cout<<"Enter the list of directed edges : "<<endl;
    for(int i=0;i<=n;i++)
    {
        adj[i].clear();
        for(int j=0;j<=n;j++)
        {
            G[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        G[u][v] = 1;
        adj[u].push_back(v);
    }
    //cout<<"Enter the source : ";
    cin>>src;

    BFS(src);
    cout<<"\nBFS Tree : \n"<<endl;
    printTreeAdjList(n);

    DFS(src);
    cout<<"\nDFS Tree : \n"<<endl;
    printTreeAdjList(n);

    return 0;
}

/* input

4 3
1 2
2 3
1 3
1


14 12
1 2
1 3
1 4
1 5
2 6
2 7
2 8
2 9
3 10
3 11
3 12
3 13
1


16 14
1 2
1 3
1 4
2 5
2 6
3 7
3 8
3 9
8 10
8 11
10 12
12 13
13 14
11 15
1


17 15
1 2
2 3
2 4
2 5
4 6
6 7
6 9
7 10
9 11
10 12
11 13
12 14
13 15
3 8
5 16
1

*/
