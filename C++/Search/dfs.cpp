#include<bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    list<int> *adj;
    void DfsAgain(int,bool[]);
    public:
    graph(int);
    void addedge(int,int);
    void dfs(int);
};
graph :: graph(int V)
{
    this->V=V;
    adj = new list<int>[V];
}
void graph :: addedge(int v,int w)
{
    adj[v].push_back(w);
}
void graph :: dfs(int s)
{
    bool visited[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    DfsAgain(s,visited);
}
void graph :: DfsAgain(int s,bool visited[])
{
    visited[s]=true;
    cout<<s<<' ';
    list<int>::iterator i;
    for(i=adj[s].begin();i!=adj[s].end();++i)
    {
        if(!visited[*i])
        {
            visited[*i]=true;
            DfsAgain(*i,visited);
        }
    }
}
int main()
{
    graph g(5);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,3);
    g.addedge(1,2);
    g.addedge(2,4);
    g.dfs(0);
}
