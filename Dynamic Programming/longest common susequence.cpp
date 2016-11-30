#include<bits/stdc++.h>
using namespace std;
int main()
{
	int dp[200][200],len1=0,len2=0,i,j,k=0;
	string str1,str2;
	char str3[200];
	cin>>str1;
	cin>>str2;
	len1=str1.length();
	len2=str2.length();
	for(i=0;i<=len1;i++)
	{
		dp[i][0]=0;
		dp[0][i]=0;
	}
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<"\n\tLength of LCS is :"<<dp[len1][len2];
	cout<<"\n\tLCS is : ";
    i=len1;
    j=len2;
    while(1)
    {
        if(dp[i][j]==dp[i-1][j-1]+1  && str1[i-1]==str2[j-1])
        {
            str3[k++]=str1[i-1];
            i-=1;
            j-=1;
        }
        else if(dp[i][j]==dp[i-1][j])
        {
            i-=1;
        }
        else
        {
            j-=1;
        }
        if(i==0 && j==0)
            break;
    }
    cout<<strrev(str3);

}
