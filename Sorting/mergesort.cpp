#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int mid,int low,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int L[n1];
    int R[n2];
    int i,j,k;
    for(i=0;i<n1;i++)
    {
        L[i]=a[low+i];
    }
    for(i=0;i<n2;i++)
    {
        R[i]=a[mid+i+1];
    }
    i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k++]=L[i++];
        }
        else
        {
            a[k++]=R[j++];
        }
    }
    while(i<n1)
    {
        a[k++]=L[i++];
    }
    while(j<n2)
    {
        a[k++]=R[j++];
    }
}

void mergesort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,mid,low,high);
    }
}


int main()
{
    int n,a[100000],i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
