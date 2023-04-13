#include<bits/stdc++.h>
using namespace std;

int merge_count(string a, int left, int mid, int right)
{

    if(!(a[mid]==a[mid+1]+1))
        return 0;

    int m,n;
    int i = mid+2;
    n = 1;
    while(i<=right && a[i]==a[i-1]-1)
    {
        i++;
        n++;
    }
    m = 1;
    int j = mid-1;
    while(j>=left && a[j+1]==a[j]-1)
    {
        m++;
        j--;
    }

    return m*n;


}


int count_inv(string a, int start, int finish)
{
    if(finish-start<=0)
        return 0;

    int mid = (start + finish)/2;

    int na = count_inv(a,start,mid);
    int nb = count_inv(a,mid+1,finish);

    return na+nb+merge_count(a,start,mid,finish);
}


int main()
{
    string a;
    cout<<"Enter the string: ";
    cin>>a;
    cout<<"\nNumber of inverted substrings = ";
    cout<<count_inv(a,0,a.length()-1)<<endl;
}
