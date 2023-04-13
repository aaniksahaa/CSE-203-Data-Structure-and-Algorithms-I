#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>inversions;

int merge_count(int arr[], int left, int mid, int right)
{
    int cnt = 0;

    int larr[mid-left+5], rarr[right-mid+5];
    int p,q;
    int j = 0;
    for(int i=left;i<=mid;i++)
    {
        larr[j] = arr[i];
        j++;
    }
    p = j;
    j = 0;
    for(int i=mid+1;i<=right;i++)
    {
        rarr[j] = arr[i];
        j++;
    }
    q = j;

    j = 0;
    int i = 0,done = left;

    while(i<p && j<q)
    {
        if(larr[i] > rarr[j])
        {
            for(int k=i;k<p;k++)
            {
                inversions.push_back(make_pair(larr[k],rarr[j])); // This line takes O(n)
            }

            arr[done] = rarr[j];
            j++;
            done++;

            cnt += (p-i);
        }
        else
        {
            arr[done] = larr[i];
            i++;
            done++;
        }
    }

    while(j<q)
    {
        arr[done] = rarr[j];
        j++;
        done++;
    }
    while(i<p)
    {
        arr[done] = larr[i];
        i++;
        done++;
    }
    return cnt;


}

int count_inv(int arr[], int start, int finish)
{
    // Base Case
    if(finish-start<=0)
        return 0;

    int mid = (start + finish)/2;

    int a = count_inv(arr,start,mid);
    int b = count_inv(arr,mid+1,finish);

    return a+b+merge_count(arr,start,mid,finish);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<count_inv(arr,0,n-1)<<endl;

    int m = inversions.size();

    cout<<"The inverted pairs are ";
    for(int i=0;i<m-1;i++)
    {
        cout<<"("<<inversions[i].first<<","<<inversions[i].second<<"),";
    }
    cout<<"("<<inversions[m-1].first<<","<<inversions[m-1].second<<")"<<endl;

    return 0;
}
