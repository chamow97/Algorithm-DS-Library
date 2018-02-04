#include<bits/stdc++.h>

typedef long long ll;

#define rep(i,j,n) for(i=j;i<=n;i++)

#define per(i,j,n) for(i=j;i>=n;i--)

using namespace std;

void maxHeapify(ll a[],ll size,ll pos)
{
	ll maximum;
	ll l=pos*2;
	ll r=(pos*2)+1;
	if(l<=size && a[l]>=a[pos])
	{
		maximum=l;
	}
	else
	{
		maximum=pos;
	}
	if(r<=size && a[r]>=a[maximum])
	{
		maximum=r;
	}
	if(maximum!=pos)
	{
		swap(a[pos],a[maximum]);
		maxHeapify(a,size,maximum);
	}
}
int main()
{
	ll size,a[100000],i,n;
	cin>>size;
	n=size;
	rep(i,1,size)
	{
		cin>>a[i];
	}
    per(i,(size/2),1)
    {
        maxHeapify(a,size,i);
    }
    per(i,size,2)
    {
        swap(a[1],a[i]);
        --n;
        maxHeapify(a,n,1);
    }

	rep(i,1,size)
	{
		cout<<a[i]<<" ";
	}

}
