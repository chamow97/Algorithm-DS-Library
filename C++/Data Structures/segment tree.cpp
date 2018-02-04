#include<bits/stdc++.h>
using namespace std;
#define MAXIMUM 10009

void constructTree(int low, int high, int position, vector<int> &array, vector<int> &segmentArray)
{
	if(low == high)
	{
		segmentArray[position] = array[low];
	}
	else
	{
		int mid = (low + high)/2;
		constructTree(low, mid, (2*position)+1, array, segmentArray);
		constructTree(mid+1, high, (2*position)+2, array, segmentArray);
		segmentArray[position] = min(segmentArray[(2*position)+1], segmentArray[(2*position)+2]);
	}
}

int rangeQuery(int lowerBound, int upperBound, int low, int high, int position, vector<int> &segmentArray, int pos)
{
	if(lowerBound <= low && upperBound >= high) //complete overlap
	{
		return segmentArray[position];
	}
	else if(upperBound < low || lowerBound > high) // no overlap
	{
		return 10000000;
	}
	else //partial overlap
	{
		int mid = (low + high)/2;
		return min(rangeMinimumQuery(lowerBound, upperBound, low, mid, (2*position)+1, segmentArray),
		rangeMinimumQuery(lowerBound, upperBound, mid + 1, high, (2*position)+2, segmentArray));
	}
}

int main()
{
	int n, i;
	cin>>n;
	vector<int> array(n,0);
	vector<int> segmentArray(4*n, 100000);
	for(i=0; i<n; i++)
	{
		cin>>array[i];
	}
	constructTree(0, n-1, 0, array, segmentArray);
	cout<<rangeMinimumQuery(3, n-1, 0, n-1, 0, segmentArray);

}