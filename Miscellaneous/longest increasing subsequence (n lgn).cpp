#include<bits/stdc++.h>
using namespace std;

int Binary_Search(vector<int> &tail, int low, int high, int key)
{
    int mid;
    while( high - low > 1)
    {
        mid = low + (high - low)/2;

        if(tail[mid] >= key)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return high;
}


int LIS(vector<int> &arr)
{
    int length = 1;
    vector<int> tail(arr.size(),0);
    tail[0] = arr[0];
    for(size_t i = 1; i < arr.size(); i++)
    {
        if(arr[i] < tail[0])
        {
            //if arr[i] is the new smallest, it might be starting of a new LIS
            tail[0] = arr[i];
        }
        else if(arr[i] > tail[length-1])
        {
            //if arr[i] is the largest of found, append it
            tail[length++] = arr[i];
        }
        else
        {
            //tricky case, where a[i] lies in between
            //do a search on where to place it
            tail[Binary_Search(tail, -1, length - 1, arr[i])] = arr[i];
        }
    }
    return length;
}

int main()
{
    int n, length = 0;
    int i, j; //loop var
    cin>>n;
    vector<int> arr(n);
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    length = LIS(arr);
    cout<<length;
}
