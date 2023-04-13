#include<bits/stdc++.h>
#include "Heap.cpp"
using namespace std;

int main()
{
    //freopen("in1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Heap H;
    string s;
    while(cin>>s)
    {
        if(s == "FIN")
        {
            int minval = H.FindMin();
            if(minval != -1)
                cout<<"FindMin returned "<<minval<<endl;
        }
        else if(s == "EXT")
        {
            int minval = H.ExtractMin();
            if(minval != -1)
                cout<<"ExtractMin returned "<<minval<<endl;
        }
        else if(s == "INS")
        {
            int value;
            cin>>value;
            H.Insert(value);
            cout<<"INSERTED "<<value<<endl;
        }
        else if(s == "DEC")
        {
            int prevKey, newKey;
            cin>>prevKey>>newKey;
            H.DecreaseKey(prevKey,newKey);
        }
        else if(s == "PRI")
        {
            cout<<"Printing the binary heap ..."<<endl;
            cout<<"- - - - - - - - - - - - - - - - - - - -"<<endl;
            H.Print();
            cout<<"- - - - - - - - - - - - - - - - - - - -"<<endl;
        }
        else
        {
            cout<<"Invalid Input"<<endl;
        }
    }
    return 0;
}

/* Sample Inputs

INS 7
INS 10
INS 5
PRI
INS 12
INS 15
PRI
DEC 15 3
PRI
FIN
EXT
PRI




PRI
EXT
FIN
INS 16
INS 4
INS 8
INS 2
INS 5
PRI
EXT
FIN
PRI
DEC 16 3
DEC 3 7
DEC 9 1
DEC 9 2
PRI

*/
