#include<bits/stdc++.h>

using namespace std;

int countzeros(vector<int>&arr)
{
    int pos = -1;

    int n = arr.size();

    int lo = 0, hi = n-1;

    while(hi >= lo)
    {
        int mid = (lo+hi)/2;

        if(arr[mid] == 1)
        {
            lo = mid + 1;
        }
        else
        {
            if(mid == 0 || arr[mid-1]==1)
            {
                pos = mid;
                break;
            }
            else
            {
                hi = mid-1;
            }
        }
    }

    if(pos == -1)
        return 0;
    return n-pos;
}

int main()
{
    int n;

    cin>>n;
    vector<int>a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<countzeros(a);
    return 0;
}
