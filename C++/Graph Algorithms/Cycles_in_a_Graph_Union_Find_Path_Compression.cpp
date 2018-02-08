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


/*-------------------------------------------------------- */

ll gcd(ll a, ll b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a,b));
}

/*-------------------------------------------------------- */

const ll maxn = 1e6;
vec *adj = new vec[maxn];

struct subset{
	ll parent, rank;
};

vector<subset> s(maxn);
ll n, m;

ll find(ll x)
{
	if(s[x].parent != x)
	{
		s[x].parent = find(s[x].parent);
	}
	return s[x].parent;
}

void Union(ll x, ll y)
{
	ll i = find(x);
	ll j = find(y);
	if(s[i].rank < s[j].rank)
	{
		s[i].parent = j;
	}
	else if(s[j].rank < s[i].rank)
	{
		s[j].parent = i;
	}
	else
	{
		s[j].parent = i;
		s[i].rank++;

	}
}

bool isCyclic()
{
	rep(i,1,n+1)
	{
		s[i].parent = i;
		s[i].rank = 0;
	}
	rep(i,1,n+1)
	{
		ll x = find(i);
		rep(j,0,adj[i].size())
		{
			ll y = find(adj[i][j]);
			if(x == y)
			{
				return true;
			}
			Union(x, y);
		}
	}
	return false;
}

int main()
{
	fastread;
	cin >> n >> m;
	rep(i,0,m)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}
	if(isCyclic())
	{
		cout << "Cyclic";
		return 0;
	}
	cout << "Not Cyclic";
	return 0;
}