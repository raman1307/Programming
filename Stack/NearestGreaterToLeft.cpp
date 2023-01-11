#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int arr[] = {1,3,2,4};
    int sz = sizeof(arr)/sizeof(arr[0]);
    stack<int> st;
    vector<int> vec;

    for(int i=0; i<sz; i++)
    {
        if(st.size() == 0)
        {
            vec.push_back(-1);
        }
        else if(st.top() > arr[i])
        {
            vec.push_back(st.top());
        }
        else if(st.size()>0 && st.top()<=arr[i])
        {
            while(st.size()>0 && st.top()<= arr[i])
            {
                st.pop();
            }

            if(st.size() == 0)
            {
                vec.push_back(-1);
            }
            else{
                    vec.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    for(auto i : vec)
    {
        cout<<i<<" ";
    }
    return 0;
}
