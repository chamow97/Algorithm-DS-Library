#include<bits/stdc++.h>
using namespace std;
int main()
{
	int coins[] = {0,1,2,3};
	int numberOfCoins = 3;
	int totalSum;
	int i,j;
	cin>>totalSum;
	int dp[20][20];
	for(i=0;i<=numberOfCoins;i++)
	{
		dp[i][0] = 1;
	}
	for(i=1;i<=totalSum;i++)
	{
		dp[0][i] = 0;
	}
	for(i=1;i<=numberOfCoins;i++)
	{
		for(j=1;j<=totalSum;j++)
		{
			if(j<coins[i])
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
			}
		}
	}
	cout<<dp[numberOfCoins][totalSum];

}
