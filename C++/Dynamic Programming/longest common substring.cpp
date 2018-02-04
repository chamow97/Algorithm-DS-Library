#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j; //loop var
	int pos1, pos2;
	int length1, length2;
	int maxLength = 0;
	string str1, str2, maxString;
	cout<<"\nEnter the two strings : ";
	cin>>str1>>str2;
	length1 = str1.length();
	length2 = str2.length();
	int dp[length1+1][length2+1];
	for(i=0; i<=length1; i++)
	{
		dp[0][i] = 0;
	}
	for(i=1; i<=length2; i++)
	{
		dp[i][0] = 0;
	}
	for(i=1; i<=length1; i++)
	{
		for(j=1; j<=length2; j++)
		{
			if(str1[i-1] == str2[j-1])
			{
				dp[i][j] = 1+dp[i-1][j-1];
				if(maxLength<dp[i][j])
				{
					maxLength = dp[i][j];
					pos1 = i;
					pos2 = j;
				}
			}
			else
			{
				dp[i][j] = 0;
			}

		}
	}
	cout<<"\nLength of Longest Common Substring: ";
	cout<<maxLength;
	cout<<"\nThe Substring is : ";
	i = 0;
	while(maxLength--)
	{
		maxString[i++] = str1[pos1-1];
		pos1 -= 1;
		pos2 -= 1;
	}
	for(j = i-1; j>=0; j--)
	{
		cout<<maxString[j];
	}
}

