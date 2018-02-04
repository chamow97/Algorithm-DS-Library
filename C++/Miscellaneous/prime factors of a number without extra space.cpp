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

void primeFactors(ll num)
{
	bool isPrime = true;
	ll temp = num;
	if(num % 2 == 0)
	{
		isPrime = false;
		cout<<2<<" ";
	}
	while(num % 2 == 0)
	{
		num /= 2;
	}
	rep(i,3,sqrt(temp)+1)
	{
		if(num % i == 0)
		{
			isPrime = false;
			cout<<i<<" ";
			while(num % i == 0)
			{
				num /= i;
			}
		}
		i++;
	}
	if(isPrime)
	{
		cout<<temp;
	}
}

int main()
{
	fastread;
	ll num;
	cin>>num;
	primeFactors(num);
	return 0;
}
