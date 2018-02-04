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
#define MAXN = 100000;

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
vec smallestPrimeFactor(100001, 0);
void seive()
{
    rep(i,0,100001)
    {
        smallestPrimeFactor[i] = i;
    }
    smallestPrimeFactor[1] = 1;
    for(ll i = 2; i <= 100000; i += 2)
    {
        smallestPrimeFactor[i] = 2;
    }
    for(ll i = 3; i <= sqrt(100000); i += 2)
    {
        if(smallestPrimeFactor[i] == i)
        {
            for(ll j = i*i; j <= 100000; j += i)
            {
                if(smallestPrimeFactor[j] == j)
                {
                    smallestPrimeFactor[j] = i;
                }
            }
        }
    }
}



int main()
{
	fastread;
    ll n;
    cin>>n;
    seive();
    while(n != 1)
    {
        cout<<smallestPrimeFactor[n]<<" ";
        n = n / smallestPrimeFactor[n];
    }
	return 0;
}
