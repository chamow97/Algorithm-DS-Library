#include <iostream>
using namespace std;

void floydWarshall(int graph[100][100], int n, int e)
{
	int i,j,k;
	for(k=0; k<=n; k++)
	{
		for(i=0; i<=n; i++)
		{
			for(j=0; j<=n; j++)
			{
				if(graph[i][k] + graph[k][j] < graph[i][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
	bool isNegative = false;
	for(i=0;i<n;i++)
    {
        if(graph[n][i] != graph[n-1][i])
        {
            isNegative = true;
            break;
        }
    }
    long long minimum = 10000000000000000;
    if(isNegative == false)
    {
        for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			minimum = min(min,graph[i][j]);
		}
	}
	cout<<minimum;

    }
    else
    {
        cout<<"NULL";
    }

}

int main() {

	int j,i,graph[100][100],w,n,u,v,e;
	cin>>n;
	cin>>e;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(i != j)
			{
				graph[i][j] = 10000000000000000;
			}
			else
			{
				graph[i][j] = 0;
			}
		}
	}
	for(i=0; i<e; i++)
	{
		cin>>u>>v>>w;
		u--;
		v--;
		graph[u][v] = w;
		//For undirected or directed graphs.
		//graph[v][u] = w;
	}
	floydWarshall(graph, n, e);
	// your code goes here
	return 0;
}
