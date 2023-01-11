#include<iostream>
#include<stack>

using namespace std;
stack<int> Stk;
stack<int> supportStk;
int getMinimum()
{
    if(supportStk.size() == 0)
    {
        return -1;
    }
    return supportStk.top();
}
void push(int a)
{
    Stk.push(a);
    if((supportStk.size() == 0) || supportStk.top() >= a)
    {
        supportStk.push(a);
        return;
    }
}
int pop()
{
    if(Stk.size() == 0)
    {
        return -1;
    }
    int ans = Stk.top();
    Stk.pop();
    if(supportStk.top() == ans)
    {
        supportStk.pop();
    }
    return ans;
}
int main()
{
    int arr[] = {5,7,2,1,10,15};
    int sz = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<sz; i++)
    {
        push(arr[i]);
    }

    for(int i=0; i<sz; i++)
    {
        pop();
        cout<<"Minimum element is "<<getMinimum()<<endl;
    }

    return 0;
}
