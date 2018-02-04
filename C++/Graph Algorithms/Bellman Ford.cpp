#include<bits/stdc++.h>
using namespace std;

struct Edges
{
	int source;
	int destination;
	int weight;
};
struct Graph
{
	int numberOfNodes;
	int numberOfEdges;
	Edges e[100];
};
void printResult(int distance[], bool isNegativeCycles, int numberOfNodes, int sourceVertex)
{
	if(isNegativeCycles == true)
	{
		cout<<"\nGraph contains Negative Cost Cycle!!";
	}
	else
	{
		int i;
		cout<<"\nDistance of nodes from source vertex "<<sourceVertex<<" is : \n";
		for(i=0; i<numberOfNodes; i++)
		{
			cout<<"Vertex : "<<i<<" Distance : "<<distance[i]<<endl;
		}
	}
}
void Bellman_Ford(Graph g)
{
	int sourceVertex;
	int distance[100];
	bool isNegativeCycles = false;
	int i,j;
	int u,v,w; //graph variables
	for(i=0;i<100;i++)
	{
		distance[i] = 100000; //an arbitrary infinite number. assuming weights<100000
	}
	cout<<"\nEnter the source Vertex : ";
	cin>>sourceVertex;
	distance[sourceVertex] = 0;
	for(i=0; i<g.numberOfNodes-1; i++)
	{
		for(j=0; j<g.numberOfEdges; j++)
		{
			u = g.e[j].source;
			v = g.e[j].destination;
			w = g.e[j].weight;
			if(distance[u]!=100000 && distance[v] > distance[u] + w)
			{
				distance[v] = distance[u] + w;
			}
		}
	}
	//checking negative cycles
	for(i=0; i<g.numberOfEdges; i++)
	{
		u = g.e[i].source;
		v = g.e[i].destination;
		w = g.e[i].weight;
		if(distance[v] > distance[u] + w)
		{
			isNegativeCycles = true;
			break;
		}
	}

	printResult(distance, isNegativeCycles, g.numberOfNodes, sourceVertex);
}

int main()
{
    int i;
	Graph g;
	cout<<"\nEnter number of nodes and edges : ";
	cin>>g.numberOfNodes;
	cin>>g.numberOfEdges;
    cout<<"\nEnter the source, destination, weight of the edges : \n";
	for(i=0;i <g.numberOfEdges; i++)
	{
		cin>>g.e[i].source>>g.e[i].destination>>g.e[i].weight;
	}
	Bellman_Ford(g);
}
