#include<bits/stdc++.h>
using namespace std;
int main()
{
    int penaltyForSpace = 1;
    int penaltyForMismatch = 1;
    int dp[101][101];
    int length1, length2;
    string str1, str2;
    int i, j;//loop variables


    cout<<"\nEnter the strings(denote space by - ) : ";
    cin>>str1;
    cin>>str2;

    length1 = str1.length();
    length2 = str2.length();

    for(i = 0; i <= length1; i++)
    {
        dp[i][0] = i*penaltyForSpace;
    }

    for(i = 0; i <= length2; i++)
    {
        dp[0][i] = i*penaltyForSpace;
    }
    for(i = 1; i <= length1; i++)
    {
        for(j = 1; j <= length2; j++)
        {
            if(str1[i] == str2[j])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j-1] + penaltyForMismatch , min(dp[i-1][j] + penaltyForSpace, dp[i][j-1] + penaltyForSpace));
            }
        }
    }
    cout<<"\n\t Total Penalty : ";
    cout<<dp[length1][length2];
}
