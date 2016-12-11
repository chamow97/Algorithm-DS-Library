#include<bits/stdc++.h>
using namespace std;
int main()
{
	int length;
	int cost[]={0,2,5,7,8};
	int numberOfRods = 4;
	int dp[20][20];
	int i,j;
	cout<<"\nEnter total length of the rod : ";
	cin>>length;
	for(i=0;i<=length;i++)
	{
		dp[0][i] = i;
	}
	for(i=0;i<=numberOfRods;i++)
	{
		dp[i][0] = 0;
	}
	for(i=1;i<=numberOfRods;i++)
	{
		for(j=1;j<=length;j++)
		{
			if(j>=i)
			{
			    dp[i][j] = max(dp[i-1][j],cost[i]+dp[i][j-i]);

			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	i=numberOfRods;
	j=length;
	cout<<"\nMaximum Profit : ";
	cout<<dp[numberOfRods][length];
	cout<<"\nThe rods(its cost) are : ";
	while(1)
    {
        if(dp[i][j]==dp[i-1][j])
        {
            i=i-1;
        }
        else
        {
            cout<<i<<"("<<cost[i]<<")"<<" ";
            j=j-i;
        }
        if(i==0 || j==0)
        {
            break;
        }
    }

}
