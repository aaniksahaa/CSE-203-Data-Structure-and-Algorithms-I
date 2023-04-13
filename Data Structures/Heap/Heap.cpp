#include<bits/stdc++.h>
using namespace std;

class Heap{
    int n;  // Count of nodes in the heap
    int *arr;
    static const int DEFAULT = 100;
    int getLeft(int index)
    {
        return 2*index + 1;
    }
    int getRight(int index)
    {
        return 2*index + 2;
    }
    int getParent(int index)
    {
        return (index-1)/2;
    }
    bool isleaf(int pos)
    {
        if(getLeft(pos)>=n && getRight(pos)>=n)
            return true;
        return false;
    }
    void siftdown(int pos)    // Update n before calling this
    {
        int curr = pos;
        while(!isleaf(curr))
        {
            int l = getLeft(curr);
            int r = getRight(curr);
            int minPos = l;
            if(r<n && arr[r]<arr[l])
                minPos = r;

            if(arr[curr] < arr[minPos])
                break;

            int tmp = arr[curr];
            arr[curr] = arr[minPos];
            arr[minPos] = tmp;

            curr = minPos;
        }
    }
    void siftup(int pos)  // Update n before calling this
    {
        int curr = pos;
        while(curr > 0)
        {
            int par = getParent(curr);
            if(arr[curr] > arr[par])
            {
                break;
            }
            else
            {
                int tmp = arr[curr];
                arr[curr] = arr[par];
                arr[par] = tmp;

                curr = par;
            }
        }
    }
    void remove(int pos)  // remove an element at index pos
    {
        if(pos<0 || pos>=n)
        {
            cout<<"Index to be removed out of range"<<endl;
            return;
        }
        int tmp;

        tmp = arr[n-1];
        arr[n-1] = arr[pos];
        arr[pos] = tmp;

        n--;

        siftdown(pos);
    }
    void heapify()
    {
        for(int i=n-1;i>=0;i--)
        {
            siftdown(i);
        }
    }
public:
    Heap(int maxSize = DEFAULT)
    {
        arr = new int[maxSize];
        n = 0;
    }
    Heap(int *data, int cnt)
    {
        arr = data;
        n = cnt;
        heapify();
    }
    int FindMin()
    {
        if(n == 0)
        {
            cout<<"Sorry, Heap is empty. Cannot find minimum element."<<endl;
            return -1;
        }
        return arr[0];
    }
    int ExtractMin()
    {
        if(n == 0)
        {
            cout<<"Sorry, Heap is empty. Cannot extract minimum element."<<endl;
            return -1;
        }
        int tmp,minval;

        minval = arr[0];

        tmp = arr[n-1];
        arr[n-1] = arr[0];
        arr[0] = tmp;

        n--;

        siftdown(0);

        return minval;
    }
    void Insert(int key)
    {
        n++;
        arr[n-1] = key;
        siftup(n-1);
    }
    void DecreaseKey(int prevKey, int newKey)
    {
        if(newKey > prevKey)
        {
            cout<<"Invalid Input. New Key must be less than previous key.\n";
            return;
        }
        int index=-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i] == prevKey)
            {
                index = i;
                break;
            }
        }
        if(index == -1)
        {
            cout<<"Invalid Input. "<<prevKey<<" is absent in heap.\n";
            return;
        }
        arr[index] = newKey;
        siftup(index);

        cout<<prevKey<<" decreased to "<<newKey<<endl;
    }
    void Print()
    {
        /*
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        */
        int i = 0,level = 0,j=0,cnt=1;
        while(i < n)
        {
            if(j==0)
            {
                cout<<"Level "<<level<<": ";
            }
            cout<<arr[i];
            j++;
            if(j==cnt)  // This level is printed completely
            {
                j = 0;
                level++;
                cnt *= 2;
                cout<<endl;
            }
            else
            {
                if(i==n-1)
                {
                    cout<<endl;
                }
                else
                {
                    cout<<" ";
                }
            }
            i++;
        }
    }
};
