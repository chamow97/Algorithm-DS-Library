#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<ll> :: iterator
#define vecpit vector< pair<ll, ll> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;
typedef vector< pair<ll, ll> > vecpair;

const ll maxn = 1e5 + 10;

vec *adj = new vec[maxn];
boolean visited(maxn, false);
ll maxDiameter = 0;
ll numberOfNodes;
ll newRoot = -1;
ll counter = 0;

void input()
{
	cin >> numberOfNodes;
	rep(i,0,numberOfNodes-1)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
}

void dfs(ll s, ll counter)
{
	visited[s] = true;
	++counter;
	for(auto i : adj[s])
	{
		if(!visited[i])
		{
			if(counter >= maxDiameter)
			{
				maxDiameter = counter;
				newRoot = i;
			}
			dfs(i, counter);
		}
	}
}

void findDiameter()
{
	dfs(1ll, counter + 1);
	fill(visited.begin(), visited.end(), false);
	counter = 0;	
	dfs(newRoot, counter + 1);
}

int main()
{
	fastread;
	input();
	findDiameter();
	cout << maxDiameter;
	return 0;
}
