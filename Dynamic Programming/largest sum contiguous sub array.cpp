#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    int arr[100];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int maxSoFar=arr[0];
    int maxEnding=arr[0];
    for(i=1;i<n;i++)
    {

        maxEnding = max(arr[i],arr[i]+maxEnding);
        maxSoFar = max( maxSoFar,maxEnding);
    }
    cout<<maxSoFar;
}
