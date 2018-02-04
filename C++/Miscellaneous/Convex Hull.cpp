#include<bits/stdc++.h>
using namespace std;

stack<int> convexHull(int n, vector<pair<int, int> > &p)
{
	stack< pair<int, int> > s;
	s.push(p[0]);
	s.push(p[1]);
	int counter = 2;
	while(counter < n)
	{
		pair<int, int> current = p[counter];
		while(getAngle(current, s.top()) == -1)
		{
			current = s.top();
			s.pop();
			++counter;
		}
		s.push(current);

	}
}

bool myFunc(pair<int, int> &p1, pair<int, int> &p2)
{
	if(p1.second == p2.second)
	{
		return p1.first < p2.first;
	}
	return p1.second < p2.second;
}
int main()
{
	vector< pair<int, int> > p;
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		pair<int, int> point;
		cin>>point.first>>point.second;
		p.push_back(point);
	}
	sort(p.begin(), p.end(), myFunc);
	convexHull(n, p);
}