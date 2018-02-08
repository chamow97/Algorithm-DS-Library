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
const ll maxn = 1e5;
ll n;
vec inputArray(maxn, 0);
vec BIT(maxn * 3, 0);

void initializeBIT()
{
	rep(i,1,n+1)
	{
		ll ptr = i;
		while(ptr <= n)
		{
			BIT[ptr] += inputArray[i];
			ptr += (ptr & (-ptr));
		}
	}
}

ll query(ll range)
{
	ll answer = 0;
	while(range > 0)
	{
		answer += BIT[range];
		range -= (range & (-range));
	}
	return answer;
}

void update(ll index, ll value)
{
	while(index <= n)
	{
		BIT[index] += value;
		index += (index & (-index));
	}
}

int main()
{
	cin >> n;
	rep(i,1,n+1)
	{
		cin >> inputArray[i];
	}
	initializeBIT();
	cout << query(n) << '\n';
	update(n-2, 100);
	cout << query(n) << '\n';
	return 0;
}