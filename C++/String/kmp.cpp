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
void computeLPS(string pattern, vec &lps, ll m);

void KMP(string text, string pattern)
{
    ll n = text.length();
    ll m = pattern.length();
    vec lps(m,0);
    
    computeLPS(pattern, lps, m);
    ll i = 0, j = 0;
    while(i < n)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if(j == m)
        {
            cout<<"Pattern found at: "<<i-j<<'\n';
            j = lps[j-1];
        }
        else if(i < n && pattern[j] != text[i])
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                i = i + 1;
            }
        }
        
    }
}

void computeLPS(string pattern, vec &lps, ll m)
{
    ll len = 0;
    lps[0] = 0;
    ll i = 1;
    while(i < m)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else if(pattern[i] != pattern[len] && len != 0)
        {
            len = lps[len-1];
        }
        else
        {
            lps[i] = 0;
            ++i;
        }
    }
}

/*-------------------------------------------------------- */

int main()
{
	fastread;
	string text, pattern;
	cin>>text;
	cin>>pattern;
    	KMP(text, pattern);
	return 0;
}