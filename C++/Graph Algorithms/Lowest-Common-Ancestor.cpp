//template by chamow
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
const ll maxn = 1e5;
vec *adj = new vec[maxn];
vec depth(maxn, 0);
const ll logN = 22;
ll parentArr[maxn][logN];
ll n, q;

void dfs(ll node, ll parent)
{
	for(int i : adj[node])
	{
		if(i == parent)
		{
			continue;
		}
		depth[i] = depth[node] + 1;
		parentArr[i][0] = node;
		dfs(i, node);
	}
}

void preprocess()
{
	rep(j,1,logN)
	{
		rep(i,1,n+1)
		{
			parentArr[i][j] = parentArr[parentArr[i][j-1]][j-1];
		}
	}
}

ll LCA(ll u, ll v)
{
	// if u is at a higher height
	if(depth[u] < depth[v])
	{
		swap(u, v);
	}

	per(j,logN-1,0)
	{
		ll currVal = 1 << j;
		if(depth[u] - currVal >= depth[v])
		{
			u = parentArr[u][j];
		}
	}

	if(u == v)
	{
		return u;
	}

	per(j,logN-1,0)
	{
		if(parentArr[u][j] == 0 || parentArr[v][j] == 0 || parentArr[u][j] == parentArr[v][j])
		{
			continue;
		}
		u = parentArr[u][j];
		v = parentArr[v][j];
	}
	return parentArr[u][0];
}	

int main()
{
	fastread;
	cin >> n;
	rep(i,0,n-1)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 1);
	preprocess();
	cin >> q;
	while(q--)
	{
		ll u, v;
		cin >> u >> v;
		cout << LCA(u, v) << '\n';
	}
	return 0;
}