#include<iostream>
typedef long long ll;
using namespace std;
// Bubble Sort
int main()
{

    ll i,size,a[100000],j,t;
    cin>>size;
    for(i=0;i<size;i++)
    {
        cin>>a[i];
    }

    for(i=0;i<size;i++)
    {
        for(j=0;j<size-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }

}
