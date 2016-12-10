#include<bits/stdc++.h>
using namespace std;

int findPosition(int l, int r, vector<int> &tail, int key)
{
	while((r-l)>1)
	{
		int m = l+(r-l)/2;
		if(tail[m] >= key)
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
	return r;
}
int LIS(vector<int> &v)
{
	int i,length = v.size(),len=1;
	vector<int> tail(v.size(),0);
	tail[0] = v[0];
	if(length == 0)
	{
		return 0;
	}
	for(i = 1; i<length ; i++)
	{
		if(v[i] < tail[0])
		{
			tail[0] = v[i];
		}
		else if(v[i] > tail[len-1])
		{
			tail[len++] = v[i];
		}
		else
		{
			tail[findPosition(-1,len-1,tail,v[i])] = v[i];
		}
	}
	return len;
}

int main()
{
	std::vector<int> v{0,9,2,4,6,5,7,8,10,12};
	cout<<"\nLongest Increasing Subsequence is : "<<LIS(v);
}
