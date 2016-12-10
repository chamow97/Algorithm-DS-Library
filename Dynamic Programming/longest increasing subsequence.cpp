#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[]={0,3,4,-1,0,6,2,3};
	int maximum = 0;
	int num = 7,pos=-1;
	int dp[20];
	int i,j;
	for(i=1;i<=num;i++)
	{
		dp[i]=1;
	}
	for(i=2;i<=num;i++)
	{
		for(j=1;j<i;j++)
		{
			if(arr[i] > arr[j])
			{
				dp[i] = max(dp[i],dp[j]+1);
			}

		}
	}
	for(i=1;i<=num;i++)
	{
		if(maximum < dp[i])
        {
            maximum = dp[i];
            pos=i;
        }
	}
	cout<<"\nThe maximum length of the increasing subsequence is : "<<maximum<<".";
}
