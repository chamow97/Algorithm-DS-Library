#include<bits/stdc++.h>
using namespace std;
int main()
{
	bool dp[20][20];
	int i;
	int sum,numberOfValues=4;
	int values[]={0,2,3,8,10},j;
	cin>>sum;
	for(i=1;i<=sum;i++)
	{
		dp[0][i]=false;
	}
	for(i=0;i<=numberOfValues;i++)
	{
		dp[i][0]=true;
	}
	for(i=1;i<=numberOfValues;i++)
    {
        for(j=1;j<=sum;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=values[i])
            {
                dp[i][j]=dp[i-1][j] || dp[i-1][j-values[i]];
            }
        }
    }
    if(dp[numberOfValues][sum]==true)
    {
        cout<<"\nThe values to make up that sum is : ";
        i=numberOfValues;
        j=sum;
        while(1)
        {
            if(dp[i][j]==dp[i-1][j] && dp[i][j]==true)
            {
                i=i-1;
            }
            else
            {
                cout<<values[i]<<" ";
                j=j-values[i];
                i-=1;
            }
            if(i==0 || j==0)
            {
                break;
            }
        }
    }
    else
    {
        cout<<"\nThe given values cannot be used to give the sum of "<<sum<<".";
    }

}
