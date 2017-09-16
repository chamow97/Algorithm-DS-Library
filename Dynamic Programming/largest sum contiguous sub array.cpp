#include <bits/stdc++.h>
using namespace std;

int kadaneAlgorithm(int n, vector<int> &inputArray)
{
    int maxSoFar = -1e5;
    int maxEndingHere = 0;
    for(int i = 0; i < n; i++)
    {
        maxEndingHere = maxEndingHere + inputArray[i];
        if(maxSoFar < maxEndingHere)
        {
            maxSoFar = maxEndingHere;
        }
        if(maxEndingHere < 0)
        {
            maxEndingHere = 0;
        }
    }
    return maxSoFar;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> inputArray(n,0);
        for(int i = 0; i < n; i++)
        {
            cin>>inputArray[i];
        }
        cout<<kadaneAlgorithm(n, inputArray)<<'\n';
    }
    return 0;
}