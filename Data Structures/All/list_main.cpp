#include<bits/stdc++.h>
#include "MyListArr.cpp"
//#include "MyListLL.cpp"
using namespace std;

int main()
{
    //freopen("list_input.txt", "r", stdin);
    //freopen("list_output.txt", "w", stdout);
    int K,X,Q;
    cin>>K>>X;
    MyList<int>L;
    int a[100];
    for(int i=0;i<K;i++)
    {
        int p;
        cin>>p;
        a[i] = p;
        L.pushBack(p);
    }

    cin>>Q;
    L.print();
    for(int i=0;i<Q;i++)
    {
        int choice, param, ans;
        cin>>choice>>param;
        if(choice==1)
        {
            ans = L.size();
        }
        else if(choice==2)
        {
            L.push(param);
            ans = -1;
        }
        else if(choice==3)
        {
            L.pushBack(param);
            ans = -1;
        }
        else if(choice==4)
        {
            ans = L.erase();
        }
        else if(choice==5)
        {
            L.setToBegin();
            ans = -1;
        }
        else if(choice==6)
        {
            L.setToEnd();
            ans = -1;
        }
        else if(choice==7)
        {
            L.prev();
            ans = -1;
        }
        else if(choice==8)
        {
            L.next();
            ans = -1;
        }
        else if(choice==9)
        {
            ans = L.currPos();
        }
        else if(choice==10)
        {
            L.setToPos(param);
            ans = -1;
        }
        else if(choice==11)
        {
            ans = L.getValue();
        }
        else if(choice==12)
        {
            ans = L.find(param);
        }
        else if(choice==13)
        {
            L.clear();
            ans = -1;
        }
        else
        {
            cout<<"Sorry, Invalid Input\n";
        }
        L.print();
        cout<<ans<<"\n";
    }

    return 0;
}
