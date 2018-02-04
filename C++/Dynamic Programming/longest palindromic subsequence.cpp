#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int len=str.length();
	int dp[20][20];
	int i,j;
	for(i=0;i<len;i++)
	{
		dp[i][i]=1;
	}
	for(i=1;i<len;i++)
	{
		for(j=0;j<len-i;j++)
		{
			if(str[j]==str[j+i])
			{
				dp[j][j+i] = max(dp[j][j+i-1],dp[j+1][j+i])+2;
			}
			else
			{
				dp[j][j+i] = max(dp[j][j+i-1],dp[j+1][j+i]);
			}
		}
	}
	cout<<dp[0][len-1];
}
