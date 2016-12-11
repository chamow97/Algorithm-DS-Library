#include<bits/stdc++.h>
using namespace std;
int main()
{
	int numberOfFloors,numberOfEggs;
	int i,j,k;
	cout<<"\nEnter number of floors : ";
	cin>>numberOfFloors;
	cout<<"\nEnter number of eggs : ";
	cin>>numberOfEggs;
	int dp[20][20];
	for(i=0;i<=numberOfEggs;i++)
    {
        for(j=0;j<=numberOfFloors;j++)
        {
            dp[i][j] = 0;
        }
    }
    for(i=0;i<=numberOfFloors;i++)
    {
         dp[1][i] = i;
    }
	for(i=2;i<=numberOfEggs;i++)
	{
		for(j=1;j<=numberOfFloors;j++)
		{

			    if(i>j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    int temp = 1000000;
                    for(k=1;k<=j;k++)
                    {
                        temp = min(max(dp[i-1][k-1],dp[i][j-k]),temp);
                    }
                    dp[i][j] = temp+1;
                }
		}
	}
    cout<<"\nMinimum Number of Attempts to find it is : ";
	cout<<dp[numberOfEggs][numberOfFloors];
}
