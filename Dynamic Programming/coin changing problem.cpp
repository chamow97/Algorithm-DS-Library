#include<bits/stdc++.h>
using namespace std;
int main()
{
	int dp[200][200],totalCost,n=4,i,j;
	int cost[5]={0,1,5,6,8};
	totalCost=11;
	for(i=0;i<=totalCost;i++)
	{
		dp[0][i]=i;
	}
	for(i=0;i<=n;i++)
	{
		dp[i][0]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=totalCost;j++)
		{
			dp[i][j]=min(dp[i-1][j],dp[i][j-cost[i]]+1);
		}
	}
	cout<<"\n\tNo of coins needed : ";
	cout<<dp[n][totalCost];
	cout<<"\n\tThe value of those coins are : ";
	i=n;
	j=totalCost;
	while(1)
    {
        if(dp[i][j]==dp[i-1][j])
        {
            i=i-1;
        }
        else
        {
            j=j-cost[i];
            cout<<cost[i]<<" ";
        }
        if(i==0 && j==0)
            break;
    }

}
