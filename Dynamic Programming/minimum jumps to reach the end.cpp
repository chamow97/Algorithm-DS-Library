#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, a[100], n, answer[100], minimum[100];
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        minimum[i] = INT_MAX;
        answer[i] = i;
    }
    i = 1;
    j = 0;
    minimum[0] = 0;
    for(i=1; i<n; i++)
    {
        for(j=0; j<i; j++)
        {
            if((a[j] + j) >= i)
            {
                minimum[i] = min(minimum[i], minimum[j] + 1);
                if(minimum[i] == minimum[j] + 1)
                {
                    answer[i] = j;
                }
            }
        }
    }
    cout<<"\n\n\t Minimum number of Jumps : ";
    cout<<minimum[n-1];
    cout<<"\n\n\t Elements reached : ";
    i = n-1;
    while(i > 0)
    {
        cout<<a[i]<<" ";
        i = answer[i];
    }
    cout<<a[i];
}
