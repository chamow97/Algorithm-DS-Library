/*
Problem statement: Consider a row of n coins of values v1 . . . vn,
where n is even. We play a game against an opponent by alternating turns.
In each turn, a player selects either the first or last coin from the row, removes it from
the row permanently, and receives the value of the coin.
Determine the maximum possible amount of money we can definitely win if we move first.

Note: The opponent is as clever as the user.

*/
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


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


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

ll func(ll i, ll j, vec &arr)
{
    if(i == j)
    {
        return arr[j];
    }
    if(j == i+1)
    {
        return max(arr[i], arr[j]);
    }
    return max(arr[i] + min(func(i+1, j-1, arr), func(i+2, j, arr)), arr[j] + min(func(i, j-2, arr), func(i+1, j-1, arr)));
}

int main()
{
	fastread;
    ll n;
    cin>>n;
    vec arr(n,0);
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    ll ans = func(0ll, n-1, arr);
    cout<<ans;
	return 0;
}
