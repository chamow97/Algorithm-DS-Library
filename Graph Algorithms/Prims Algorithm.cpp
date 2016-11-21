#include<bits/stdc++.h>
using namespace std;
int V=5;
int findMinimum(int key[],bool visited[])
{
    int i,minimum=INT_MAX,keyval;
    for(i=0;i<V;i++)
    {
        if(minimum>key[i] && visited[i]==false)
        {
            minimum=key[i];
            keyval=i;
        }

    }
    return keyval;
}
void printResult(int parent[],int graph[10][10])
{
    int i;
    cout<<"\n FROM   TO         COST\n\n";

    for(i=1;i<V;i++)
    {
        cout<<"   "<<i<<" --- "<<parent[i]<<"\t    "<<graph[i][parent[i]]<<' ';
        cout<<endl;
    }

}
void Prim(int graph[10][10])
{
    int parent[V],i,k;
    int key[V];
    bool visited[V];
    for(i=0;i<V;i++)
    {
        key[i]=INT_MAX;
        visited[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(i=0;i<V-1;i++)
    {
        int u = findMinimum(key,visited);
        visited[u]=true;
        for(k=0;k<V;k++)
        {
            if(graph[u][k] && visited[k]==false && key[k]>graph[u][k])
            {
                parent[k]=u;
                key[k]=graph[u][k];
            }
        }
    }
    printResult(parent,graph);

}
int main()
{
    int graph[10][10],u,v,cost,i,j;
   cout<<"\n\n\t\t PRIM'S MINIMUM SPANNING TREE\n\t\t ---- - -------- ----";
    cout<<"\n\n\t Enter the number of nodes :";
    cin>>V;
    cout<<"\n\nEnter the (u,v) end it with (-1,-1) : \n";
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            graph[i][j]=0;
        }
    }
    for(;;)
    {
        cout<<"Enter (u,v) : ";
        cin>>u>>v;
        if(u==-1 || v==-1)
            break;
        cout<<"\n Enter its cost : ";
        cin>>cost;
        graph[u][v]=cost;
        graph[v][u]=cost;
    }
    Prim(graph);
}
