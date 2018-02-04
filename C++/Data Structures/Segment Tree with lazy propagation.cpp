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
vec arr(1000, 0);
vec segmentTree(4*1000, 0);
vec lazyTree(4*1000, 0);
/*-------------------------------------------------------- */

void constructTree(ll a, ll b, ll position)
{
    if(a > b)
    {
        return;
    }
    if(a == b)
    {
        segmentTree[position] = arr[a];
    }
    else
    {
        ll mid = (a + b)/2;
        constructTree(a, mid, (2*position)+1);
        constructTree(mid+1, b, (2*position)+2);
        segmentTree[position] = segmentTree[(2*position)+1] + segmentTree[(2*position)+2];
    }
}

void updateTree(ll position, ll a, ll b, ll i, ll j, ll value)
{
    //if the ith node is to be updated
    if(a > b)
    {
        return;
    }
    if(lazyTree[position] != 0)
    {
        segmentTree[position] += (lazyTree[position]*(b-a+1));
        if(a != b)
        {
            lazyTree[(position*2)+1] += lazyTree[position];
            lazyTree[(position*2)+2] += lazyTree[position];
        }
        lazyTree[position] = 0;
    }
    if(a > b || b < i || a > j)
    {
        return;
    }
    if(a >= i && b <= j)
    {
        segmentTree[position] += (value*(b-a+1));
        if(a != b)
        {
            lazyTree[(position*2)+1] += value;
            lazyTree[(position*2)+2] += value;
        }
        return;
    }
    ll mid = (a+b)/2;
    updateTree((position*2)+1, a, mid, i, j, value);
    updateTree((position*2)+2, mid+1, b, i, j, value);
    segmentTree[position] = segmentTree[(position*2)+1] + segmentTree[(position*2)+2];
}

ll queryTree(ll position, ll a, ll b, ll i, ll j)
{
    if(a > b || b < i || a > j)
    {
        return 0;
    }
    if(lazyTree[position] != 0)
    {
        segmentTree[position] += (lazyTree[position]*(b-a+1));
        if(a != b)
        {
            lazyTree[(2*position)+1] += lazyTree[position];
            lazyTree[(2*position)+2] += lazyTree[position];
        }
        lazyTree[position] = 0;

    }
    if(a >= i && b <= j)
    {
        return segmentTree[position];
    }
    ll mid = (a+b)/2;
    return queryTree((2*position)+1, a, mid, i, j) + queryTree((2*position)+2, mid+1, b, i, j);
}

/*-------------------------------------------------------- */

int main()
{
	fastread;
	ll n = 12;
    constructTree(0, n-1, 0);
    updateTree(0, 0, n-1, 0, 6, 50);
    updateTree(0, 0, n-1, 7, 10, 100);
    updateTree(0, 0, n-1, 11, n-1, -200);
    cout<<queryTree(0, 0, n-1, 0, 6);
	return 0;
}
