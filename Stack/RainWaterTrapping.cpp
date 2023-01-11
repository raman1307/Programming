#include<iostream>
#include<vector>

using namespace std;
int Max(int a, int b)
{
    return (a > b)?a:b;
}
int Min(int a, int b)
{
    return (a<b)?a:b;
}
int MaximumRainTrappingArea(int arr[], int sz)
{
    int Sum = 0;
    int water[sz];
    int maxLeft[sz];
    int maxRight[sz];

    maxLeft[0] = arr[0];
    for(int i=1; i<sz; i++)
    {
        maxLeft[i] = Max(maxLeft[i-1], arr[i]);
        //cout<<maxLeft[i]<<endl;
    }

    maxRight[sz-1] = arr[sz-1];
    for(int i=sz-2; i>=0; i--)
    {
        maxRight[i] = Max(maxRight[i+1], arr[i]);
        //cout<<maxRight[i]<<endl;
    }

    for(int i=0; i<sz; i++)
    {
        water[i] = Min(maxRight[i], maxLeft[i]) - arr[i];
        Sum += water[i];

    }
    cout<<"Sum = "<<Sum<<endl;
    return  Sum;
}
int main()
{
    int arr[] = {3,0,0,2,0,4};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int maxArea = MaximumRainTrappingArea(arr, sz);
    cout<<"Maximum Rain Water Trapping area : "<<maxArea<<endl;

    return 0;
}
