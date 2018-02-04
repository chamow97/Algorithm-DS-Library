#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)

typedef long long ll;

char a[2001],b[2001];
int dp[2001][2001];
int main()
{
	int len1,len2;
	cin>>a;
	cin>>b;
	len1=strlen(a);
	len2=strlen(b);
	rep(i,0,2001)
	{
		dp[0][i]=i;
	}
	rep(i,0,2001)
	{
		dp[i][0]=i;
	}
	rep(i,1,len1+1)
	{
		rep(j,1,len2+1)
		{
			if(a[i-1]==b[j-1])
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=(min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])))+1;
			}
		}
	}

	cout<<dp[len1][len2];
	return 0;
}
