#include<bits/stdc++.h>
using namespace std;
int V;
void printSolution(int shortestDistance[],int s)
{
    cout<<"\n\tStart Vertex \t\t End Vertex \t\t Shortest Distance";
    for(int i=0;i<V;i++)
    {
        cout<<"\n\t     "<<s<<"\t\t            "<<i<<"\t\t            "<<shortestDistance[i];
    }
    cout<<"\n\n\t\t Where "<<INT_MAX<<" is infinity!!";
}
int minDistance(int shortestDistance[],bool visited[])
{
    int i,distance=INT_MAX;
    int index;
    for(i=0;i<V;i++)
    {
        if(!visited[i]&&shortestDistance[i]<=distance)
        {
            distance=shortestDistance[i];
            index = i;
        }
    }
    return index;
}

void Dijkstras(int adjMatrix[10][10],int s)
{
    bool visited[V];
    int shortestDistance[V];
    int i;
    for(i=0;i<V;i++)
    {
        visited[i]=false;
        shortestDistance[i]=INT_MAX;
    }
    shortestDistance[s]=0;
    for(i=0;i<V-1;i++)
    {
        int u=minDistance(shortestDistance,visited);
        visited[u]=true;
        for(int v=0;v<V;v++)
        {
            if(!visited[v] &&
                shortestDistance[v]!=0 &&
                 adjMatrix[u][v]!=0 &&
                 shortestDistance[v]>shortestDistance[u]+adjMatrix[u][v] )
            {
                shortestDistance[v]=shortestDistance[u]+adjMatrix[u][v];
            }
        }
    }
    printSolution(shortestDistance,s);

}

int main()
{
    int u,v,i,j,s,distance;
    cout<<"\n\t\t DIJKSTRA'S ALGORITHM!!!";
    cout<<"\n\n\t Enter the number of vertices : ";
    cin>>V;
    int adjMatrix[10][10];
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            adjMatrix[i][j]=0;
        }
    }
    cout<<"\n\n\t Enter (u,v) and its length:(end it by giving -1 for u and v): \n";
    for(;;)
    {
        cout<<"\nEnter (u,v): ";
        cin>>u>>v;
        if(u==-1 || v==-1)
            break;
        cout<<"\nEnter it distance : ";
        cin>>distance;
        adjMatrix[u][v]=distance;
        adjMatrix[v][u]=distance;

    }
    cout<<"\n\n\t Enter source vertex : ";
    cin>>s;

    Dijkstras(adjMatrix,s);
}
