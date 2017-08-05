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
vec feb(1000, 0);

ll febonacci(ll n)
{
    ll k;
    if(feb[n] != 0)
    {
        return feb[n];
    }
    if(n == 0)
    {
        feb[n] = 0;
    }
    else if(n == 1 || n == 2)
    {
        feb[n] = 1;
    }
    else if(!(n&1))
    {
        k = n/2;
        feb[n] = ((2*febonacci(k-1) + febonacci(k))*febonacci(k));
    }
    else
    {
        k = (n+1)/2;
        feb[n] = (febonacci(k-1)*febonacci(k-1) + febonacci(k) * febonacci(k));
    }
    return feb[n];
}

int main()
{
	fastread;
    ll n;
    cin>>n;
    cout<<febonacci(n);
	return 0;
}
