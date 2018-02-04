#include<bits/stdc++.h>
using namespace std;

int partition(int low,int high,int a[])
{
	int i,j,x=a[high];
	i=low-1;
	for(j=low;j<high;j++)
	{
		if(a[j]<=x)
		{
			i+=1;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[high]);
	return i+1;
}
void quicksort(int low,int high,int a[])
{
	if(low<high)
	{
		int pivot=partition(low,high,a);
		quicksort(low,pivot-1,a);
		quicksort(pivot+1,high,a);
	}
}
int main()
{
	int n,i,a[100000];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quicksort(0,n-1,a);
	for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
