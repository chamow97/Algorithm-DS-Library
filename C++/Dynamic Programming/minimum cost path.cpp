#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[100][100],dp[100][100];
    int n,m,i,j;
    cin>>n>>m;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0; i<=n; i++)
    {
        dp[i][0] = 0;
    }

    for(i=0; i<=m; i++)
    {
        dp[0][i] = 0;
    }
    for(j=1; j<=m; j++)
    {
        dp[1][j] = a[1][j] + dp[1][j-1];
    }
    for(i=1; i<=n; i++)
    {
        dp[i][1] = a[i][1] + dp[i-1][1];
    }
    for(i=2; i<=n; i++)
    {
        for(j=2; j<=m; j++)
        {

                dp[i][j] = a[i][j] + min(dp[i-1][j], dp[i][j-1]);

        }

    }
    cout<<"\n\t Minimum Cost : "<<dp[n][m];
    i = n;
    j = m;
    cout<<"\n\t Selected Element(s) : ";
    while(i>0 && j>0)
    {
        if(a[i][j] + dp[i-1][j] == dp[i][j])
        {
            cout<<a[i][j]<<" ";
            i -= 1;
        }
        else
        {
            cout<<a[i][j]<<" ";
            j -= 1;
        }
    }
}
