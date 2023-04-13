#include<bits/stdc++.h>
#define LAST 1
#define MIDDLE 2
#define RANDOM 3
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int random(int l,int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

set<int>notfixed;
int mode;

int part(vector<int>&a,int p, int r)
{
    if(mode == MIDDLE)
    {
        int mid = ceil(double((p+r)/2.0));
        swap(a[mid],a[r]);
    }
    if(mode == RANDOM)
    {
        int id = random(p,r);
        swap(a[id],a[r]);
    }
    int x = a[r];
    int i = p-1;
    for(int j=p;j<r;j++)
    {
        if(a[j] <= x)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    //cout<<endl<<i+1<<endl;
    notfixed.erase(i+1);
    return i+1;

}
void show(vector<int>&a)
{
    cout<<endl<<endl;
    int n = a.size();
    for(int i=0;i<n;i++)
    {
        printf("%4d ",a[i]);
        //cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(notfixed.size()==1 || notfixed.find(i)==notfixed.end())
        {
            if(a[i]/10 == 0)
                printf("   ^ ");
            else
                printf("  ^  ");
        }
        else
        {
            printf("     ");
        }
    }
    cout<<endl<<endl;
}
void quicksort(vector<int>&a,int p, int r)
{
    int ok = 0;
    if(p>=r)
    {
        if(notfixed.size()>0 && r == *notfixed.rbegin())
        {
            show(a);
        }
        if(p==r)
        {
            notfixed.erase(p);
        }
        return;
    }
    if(r == *notfixed.rbegin())
    {
        ok = 1;
    }
    int q = part(a,p,r);
    if(ok)
        show(a);
    quicksort(a,p,q-1);
    quicksort(a,q+1,r);
}
int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    for(int i=0;i<n;i++)
        notfixed.insert(i);

    vector<int>a;
    cout<<"\nEnter the elements: \n\n";
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        a.push_back(p);
    }
    cout<<"\nOptions for pivot: 1.Last 2.Middle 3.Random\n\n";
    cout<<"Enter choice: ";
    cin>>mode;
    cout<<"\n\nSteps while sorting: \n";
    quicksort(a,0,n-1);
    cout<<"\nElements after sorting: \n\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/* 2019-20-3(a)

10
10 30 50 70 90 100 80 60 40 20
2

*/

/* 2017-18-2(b)

14
6 1 7 2 8 3 9 4 10 5 11 17 4 5
1

*/
