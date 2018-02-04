#include<bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    list<int> *adj;
    public:
    graph(int);
    void addedge(int,int);
    void bfs(int);
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
void graph :: bfs(int s)
{
    bool *visited = new bool[V];
    int i;
    for(i=0;i<V;i++)
        visited[i] = false;
    
    list<int> :: iterator it;
    list<int> q;
    q.push_back(s);
    visited[s] = true;
    while(!q.empty())
    {
        s=q.front();
        cout<<s<<' ';
        q.pop_front();
            for(it=adj[s].begin();it!=adj[s].end();++it)
        {
            if(!visited[*it])
            {
                visited[*it] = true;
                q.push_back(*it);
            }
        }
    }
    
}
int main()
{
    graph g(6);
    g.addedge(0,1);
    g.addedge(0,3);
    g.addedge(0,4);
    g.addedge(0,5);
    g.addedge(5,2);
    g.addedge(2,1);
    g.bfs(0);
}
