#include<bits/stdc++.h>
using namespace std;

struct Edge
{
	int source;
	int destination;
};

struct Graph
{
	int vertex;
	int edges;
	struct Edge E[100];
};
int find(int parent[],int i)
{
	if(parent[i]==-1)
	{
		return i;
	}
	else
	{
		return find(parent,parent[i]);
	}
}
void Union(int parent[],int x,int y)
{
	int x1 = find(parent,x);
	int y1 = find(parent,y);
	parent[x1] = y1;
}

bool isCyclic(Graph graph)
{
	int i;//loop var
	int parent[100];
	for(i=0;i<graph.vertex;i++)
	{
		parent[i] = -1;
	}
	for(i=0; i<graph.edges; i++)
	{
		int x = find(parent, graph.E[i].source);
		int y = find(parent, graph.E[i].destination);
		if(x == y)
		{
			return true;
		}
		Union(parent, graph.E[i].source, graph.E[i].destination);
	}
	return false;
}

int main()
{
	Graph G;
    G.edges = 3;
    G.vertex = 3;
	G.E[0].source = 0;
	G.E[1].source = 1;
	G.E[2].source = 0;
	G.E[0].destination = 1;
	G.E[1].destination = 2;
	G.E[2].destination = 2;
	if(isCyclic(G) == true)
	{
		cout<<"Graph has cycles.";
	}
	else
	{
		cout<<"Graph do no have any cycles.";
	}

}
