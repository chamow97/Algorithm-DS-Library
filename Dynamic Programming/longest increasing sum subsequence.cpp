#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[100], solution[100], temp[100],n,i,j,maximum=0,pos = -1;
	cin>>n;
	for(i=0; i<n; i++)
	{
		cin>>a[i];
	}
	for(i=0; i<n; i++)
	{
		temp[i] = a[i];
		solution[i] = i;
	}
	for(i=1; i<n; i++)
	{
		for(j=0; j<i; j++)
		{
			if(a[j] < a[i])
			{
				temp[i] = max(temp[i], temp[j] + a[i]);
				if(temp[i] == temp[j] + a[i])
				{
					solution[i] = j;
				}
			}
		}
	}
	for(i=0; i<n; i++)
	{
		maximum = max(maximum, temp[i]);
		if(maximum == temp[i])
		{
			pos = i;
		}
	}
	cout<<"Solution : ";
	cout<<maximum<<" (";
	while(maximum >0)
	{
		cout<<a[pos]<<" ";
		maximum -= a[pos];
		pos = solution[pos];

	}
	cout<<").";

}