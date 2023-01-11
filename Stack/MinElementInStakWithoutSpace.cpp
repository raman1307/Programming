#include<iostream>
#include<stack>

using namespace std;
stack<int> stk;
int Min = 0;

int top()
{
    if(stk.size() == 0) { return -1; }
    if(stk.top()>=Min)
    {
        return stk.top();
    }
    else if(stk.top() < Min)
    {
        return Min;
    }
}
void pop()
{
    if(stk.size() == 0)
    {
        return;
    }
    else
    {
        if(stk.top() >= Min)
        {
            stk.pop();
        }
        else if(stk.top() < Min)
        {
            Min = 2*Min-stk.top();
            stk.pop();
        }
    }
}
void push(int x)
{
    if(stk.size() == 0)
    {
        stk.push(x);
        Min = x;
    }
    else
    {
        if(x >= Min)
        {
            stk.push(x);
        }
        else if(x < Min)
        {
            stk.push(2*x - Min);
            Min = x;
        }
    }
}
int main()
{
    int arr[] = {5,3,2,7,10,6};
    int sz = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<sz; i++)
    {
        push(arr[i]);
        cout<<Min<<endl;
    }
    pop();
    pop();
    pop();
    pop();
    cout<<Min<<endl;

    return 0;
}
