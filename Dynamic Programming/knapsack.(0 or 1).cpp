#include<bits/stdc++.h>
using namespace std;
int main()
{
	int dp[200][200],i,j,n=4;
	int weight[]={0,1,3,4,5};
	int cost[]={0,1,4,5,7};
	int totalWeight=7;
	for(i=0;i<=n;i++)
	{
		dp[i][0]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=totalWeight;j++)
		{
			if(j>=weight[i])
			{
				dp[i][j]=max(cost[i]+dp[i-1][j-weight[i]],dp[i-1][j]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<"\n\tTotal Value of selected items : "<<dp[n][totalWeight];
	i=n;
	j=totalWeight;
	cout<<"\n\tThe weight and its value selected : (format:weight(value)) : ";
	while(1)
    {
        if(dp[i][j]==dp[i-1][j])
        {
            i-=1;
        }
        else
        {
            cout<<weight[i]<<"("<<cost[i]<<")"<<" ";
            j-=weight[i];
            i-=1;
        }
        if(i==0 && j==0)
        {
            break;
        }
    }

    }



