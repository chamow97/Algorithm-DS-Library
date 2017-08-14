#include<bits/stdc++.h>
using namespace std;


void stockBuySell(int n, vector<int> &price, int transactions, int dp[][100+1])
{
	for(int i = 0; i <= transactions; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			dp[i][j] = 0;
		}
	}
	int maxDiff = -1e3;
	for(int i = 1; i < transactions+1; i++)
	{
		maxDiff = dp[i-1][0] - price[0];
		for(int j = 1; j < n; j++)
		{
			dp[i][j] = max(dp[i][j-1], maxDiff + price[j]);
			maxDiff = max(maxDiff, dp[i-1][j] - price[j]);
			// cout<<dp[i][j]<<" ";	
		}
		// cout<<endl;
	}

	cout<<"Total profit : "<<dp[transactions][n-1]<<'\n';
	int i = transactions, j = n-1;
	while(i > 0 && j > 0)
	{
		while(dp[i][j] == dp[i][j-1])
		{
			--j;
		}
		cout<<"Sell at day "<<j<<"\n";
		int diff = dp[i][j] - price[j];
		--i;
		while((dp[i][j] - price[j]) != diff)
		{
			--j;
		}
		cout<<"Buy at day "<<j<<'\n';	
	}
}

int main()
{
	int n;
	cin>>n;
	vector<int> price(n+1,0);
	for(int i = 0; i < n; i++)
	{
		cin>>price[i];
	}
	int transactions;
	cin>>transactions;
	int dp[101][101];
	stockBuySell(n, price, transactions, dp);
}