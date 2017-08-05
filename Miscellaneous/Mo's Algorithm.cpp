/*
Problem Statement: Given an array of size N. All elements of array <= N. You need to answer M queries. Each query is of the form L, R. You need to answer the count of values in range [L, R] which are repeated at least 3 times.
Example: Let the array be {1, 2, 3, 1, 1, 2, 1, 2, 3, 1} (zero indexed)
Query: L = 0, R = 4. Answer = 1. Values in the range [L, R] = {1, 2, 3, 1, 1} only 1 is repeated at least 3 times.
Query: L = 1, R = 8. Answer = 2. Values in the range [L, R] = {2, 3, 1, 1, 2, 1, 2, 3} 1 is repeated 3 times and 2 is repeated 3 times. Number of elements repeated at least 3 times = Answer = 2.

Thanks Anudeep :)
Tutorial Link:  https://blog.anudeep2011.com/mos-algorithm/
*/
#include<bits/stdc++.h>
using namespace std;
int block = 0;
bool cmp(set<int, int> &a, set<int, int> &b)
{
    if(a.first/block != b.first/block)
    {
        return a.first/block < b.first/block;
    }
    return a.second < b.second;
}

int main()
{
    int n, m, l, r;
    int i, j; //loop var
    cin>>n>>m;
    block = sqrt(n);
    vector<int> arr(n,0);
    set<int, int> queries(m);
    vector<int> answer(m,0);
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(i=0; i<m; i++)
    {
        cin>>l>>r;
        queries[i].first = l;
        queries[i].second = r;
    }
    vector<int> counter(100000, 0);
    sort(queries, queries + m, cmp);
    int currL = 0, currR = 0, L, R;
    for(i=0; i<m; i++)
    {
        L = queries[i].first;
        R = queries[i].second;
        while(currL < L)
        {
            remove(currL);
            currL++;
        }
        while(currL > L)
        {
            add(currL-1);
            currL--;
        }

    }
}
