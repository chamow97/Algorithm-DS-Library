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
#define vecpairr vector< pair<ll, pair<ll, ll> > >
/*-------------------------------------------------------- */

struct Box{
    ll l, b, h;

};

bool myComp(struct Box &p1, struct Box &p2)
{
    ll base1 = (p1.l * p2.b);
    ll base2 = (p2.l * p2.b);
    return base1 > base2;
}

int main()
{
	fastread;
    vector<Box> p;
    ll n, l, b, h;
    cin>>n;
    rep(i,0,n)
    {
        Box B, B1, B2;
        cin>>B.l>>B.b>>B.h;
        p.pb(B);
        B1.l = B.h;
        B1.b = B.b;
        B1.h = B.l;
        p.pb(B1);
        B2.l = B.b;
        B2.b = B.l;
        B2.h = B.h;
        p.pb(B2);
    }
    sort(p.begin(), p.end(), myComp);
    vec maxHeight(3*n, 0);
    vec solution(3*n, 0);
    rep(i,0,3*n)
    {
        maxHeight[i] = p[i].h;
        solution[i] = i;
    }
    rep(i,1,3*n)
    {
        rep(j,0,i)
        {
            if(p[j].l > p[i].l && p[j].b > p[i].b)
            {
                // box is eligible
                if(maxHeight[i] < p[i].h + maxHeight[j])
                {
                    maxHeight[i] = p[i].h + maxHeight[j];
                    solution[i] = j;
                }
            }
        }
    }
    ll maximum = 0;
    ll maxPos = -1;
    rep(i,0,3*n)
    {
        if(maximum < maxHeight[i])
        {
            maximum = maxHeight[i];
            maxPos = i;
        }
    }
    cout<<maximum<<'\n';
    while(maxPos > 0)
    {
        cout<<p[maxPos].l<<" "<<p[maxPos].b<<" "<<p[maxPos].h<<" "<<maxHeight[maxPos]<<"\n";
        maxPos = solution[maxPos];
    }
    return 0;
}
