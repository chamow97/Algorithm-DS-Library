#include<bits/stdc++.h>
using namespace std;
float squareRoot(int x, float precision)
{
    float low = 0.0, high = x*1.0, mid;
    mid = (low+high)/2;
    while(!(mid*mid >= x - precision && mid <= x + precision))
    {
        mid = (low + high)/2;
        if(mid*mid > x + precision)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return mid;

}
int main()
{
    float answer = 0.0;
    float precision = 0.5;
    int x;
    cin>>x;
    answer = squareRoot(x, precision);
    cout<<answer;
}
