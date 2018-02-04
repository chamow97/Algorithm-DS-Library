#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, j, maximum=0;
    cin>>n>>m;
    vector<vector<int> >mat(n+1, vector<int>(m+1));
    vector<vector<int> >ans(n+1, vector<int>(m+1));
    ans.push_back(vector<int> ());
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            cin>>mat[i][j];
        }
    }
    for(i=0; i<=n; i++)
    {
        ans[i][0] = 0;
    }
    for(i=0; i<=m; i++)
    {
        ans[0][i] = 0;
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(mat[i][j] == 0)
            {
                ans[i][j] = 0;
            }
            else
            {
                ans[i][j] = 1 + min(ans[i-1][j], min(ans[i][j-1], ans[i-1][j-1]));
            }
            maximum = max(maximum, ans[i][j]);
        }
    }
    cout<<maximum;

}
