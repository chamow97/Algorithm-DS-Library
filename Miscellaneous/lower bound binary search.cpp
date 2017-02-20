#include<bits/stdc++.h>
using namespace std;

int lowerBound(int a[], int n, int key)
{
	int low = 0, high = n-1, mid, pos = -1;
	while(low <= high)
	{
		mid = (low + high)/2;
		if(a[mid] < key)
		{
			low = mid+1;
		}
		
		else
		{
			pos = mid;
			high = mid-1;
		}

	}
	return pos;
}

int main()
{
	int n,a[10000],pos,query,key;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	sort(a, a+n);
	cin>>query;
	while(query--)
	{
		cin>>key;
		int pos = lowerBound(a,n,key);
		cout<<pos<<endl;
	}
	
}