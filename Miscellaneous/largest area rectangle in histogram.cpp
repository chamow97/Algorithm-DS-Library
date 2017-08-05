#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int maxArea = 0, temp;
	int i,j;
	cin>>n;
	vector<int> a(n);
	stack<int> s;

	for(i=0; i<n; i++)
	{
		cin>>a[i];
	}
	for(i=0; i<n;)
	{

		if(s.empty() || a[i] >= a[s.top()])
		{
			s.push(i);
			++i;
		}
		else
		{
				temp = s.top();
				s.pop();
				if(s.size() == 0)
				{
					maxArea = max(maxArea, a[temp] * i);
				}
				else
				{
					maxArea = max(maxArea, (a[temp] * (i - s.top() - 1)));
				}
		}
	}
	while(s.size() > 0)
	{
		temp = s.top();
		s.pop();
		if(s.size() == 0)
		{
			maxArea = max(maxArea, a[temp] * i);
		}
		else
		{
			maxArea = max(maxArea, (a[temp] * (i - s.top() - 1)));
		}

	}
	cout<<maxArea<<endl;
}
