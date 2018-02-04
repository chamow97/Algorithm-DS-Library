#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,k,n;
	cin>>n;
	vector<int> probability(n+1);
	vector< vector<int> > a(n+2, vector<int>(n+2));
	vector< vector<int> > answer(n+1, vector<int>(n+2));
	for(i=1; i<=n; i++)
	{
		cin>>probability[i];
	}
	for(i=0; i<=n; i++)
	{
		for(j=0; j<=n; j++)
		{
			if(i == j-1)
			{
				a[i][j] = 0;
				answer[i][j] = 0;
			}
			if(i == j)
			{
				a[i][j] = probability[i];
				answer[i][j] = i;
			}
		}
	}
	a[n+1][n] = 0;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			for()
		}
	}
}