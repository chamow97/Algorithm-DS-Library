#include<bits/stdc++.h>
using namespace std;

struct Edge
{
	int source;
	int destination;
	int weight;
};

struct Graph
{
	int noOfEdges;
	int noOfVertices;
	Edge e[100];
};

struct Subset
{
	int rank;
	int parent;
};

bool myFunction(Edge a, Edge b)
{
	return a.weight < b.weight;
}
int Find(Subset subset[], int x)
{
	if(subset[x].parent != x)
    {
        subset[x].parent = Find(subset, subset[x].parent);
    }
    return subset[x].parent;
}
void Union(Subset subset[], int x, int y)
{
	int xParent = Find(subset, x);
	int yParent = Find(subset, y);
	if(subset[xParent].rank < subset[yParent].rank)
	{
		subset[xParent].parent = yParent;
	}
	else if(subset[xParent].rank > subset[yParent].rank)
	{
		subset[yParent].parent = xParent;
	}
	else
	{
		subset[yParent].parent = xParent;
		subset[xParent].rank++;
	}
}
void printResult(Edge result[], Graph graph)
{
	int i;
	cout<<"\n\n\nThe Edges int the Minimum Spanning Tree is : (source, Destination, Weight) Format : \n";
	for(i=0;i<graph.noOfVertices-1;i++)
	{
		cout<<result[i].source<<" , "<<result[i].destination<<" , "<<result[i].weight<<".\n\n";
	}

}
void KruskalMST(Graph graph)
{
	Edge result[graph.noOfVertices];
	Subset subset[graph.noOfVertices];
	int edges=0;
	int i=0;
	sort(graph.e, graph.e+graph.noOfEdges, myFunction);
	for (i = 0; i < graph.noOfVertices; ++i)
	{
		subset[i].rank = 0;
		subset[i].parent = i;
	}
	i=0;
	while(edges < graph.noOfVertices-1)
	{
		Edge nextEdge = graph.e[i];
		i++;
		int x = Find(subset,nextEdge.source);
		int y = Find(subset,nextEdge.destination);
		if(x!= y)
		{
			result[edges] = nextEdge;
			edges++;
			Union(subset, x, y);
		}

	}
	printResult(result, graph);

}
int main()
{
	Graph graph;
	cout<<"\nEnter number of Vertices and Edges : ";
	cin>>graph.noOfVertices;
	cin>>graph.noOfEdges;
	cout<<"\nEnter source, destination, weight of all edges in this order : \n";
	int i;
	for(i=0; i<graph.noOfEdges; i++)
	{
		cin>>graph.e[i].source>>graph.e[i].destination>>graph.e[i].weight;
	}
	KruskalMST(graph);
	return 0;
}
