#include<bits/stdc++.h>
#include "MyQueueLL.cpp"
//#include "MyQueueArr.cpp"
#include "MyStackLL.cpp"
//#include "MyStackArr.cpp"
using namespace std;

int main()
{
    freopen("qs_input.txt", "r", stdin);
    freopen("qs_output.txt", "w", stdout);
    int K,X,M,Y,q,p,choice,param;
    cin>>K>>X;
    MyQueue<int>Q(X);
    for(int i=0;i<K;i++)
    {
        cin>>p;
        Q.enqueue(p);
    }
    cin>>M>>Y;
    MyStack<int>S(Y);
    for(int i=0;i<M;i++)
    {
        cin>>p;
        S.push(p);
    }
    cin>>q;
    Q.print();
    S.print();
    for(int i=0;i<q;i++)
    {
        int ans;
        cin>>choice>>param;
        if(choice==1)
        {
            Q.clear();
        }
        else if(choice==2)
        {
            Q.enqueue(param);
            ans = -1;
        }
        else if(choice==3)
        {
            ans = Q.dequeue();
        }
        else if(choice==4)
        {
            ans = Q.length();
        }
        else if(choice==5)
        {
            ans = Q.frontValue();
        }
        else if(choice==6)
        {
            ans = Q.rearValue();
        }
        else if(choice==7)
        {
            ans = Q.leaveQueue();
        }
        else if(choice==8)
        {
            S.clear();
            ans = -1;
        }
        else if(choice==9)
        {
            S.push(param);
            ans = -1;
        }
        else if(choice==10)
        {
            ans = S.pop();
        }
        else if(choice==11)
        {
            ans = S.length();
        }
        else if(choice==12)
        {
            ans = S.topValue();
        }
        else
        {
            cout<<"Sorry, Invalid Choice\n";
        }
        Q.print();
        S.print();
        cout<<ans<<"\n";
    }
    return 0;
}

/*

4 8
1 4 5 7
5 12
6 5 1 3 2
24
2 9
3 0
1 0
3 0
2 3
4 0
5 1
2 6
6 0
2 9
7 0
9 7
8 0
10 0
9 3
9 7
11 0
12 0
1 0
8 0
2 9
3 0
9 2
10 0


/*

4 8
20 23 12 15
4 8
20 23 12 15
6
1 1
2 19
6 0
9 -1
10 0
12 0

*/
