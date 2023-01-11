/*Consecutive smaller or equal before it

Count number of element that is consecutive smaller or equal before it

It is same as if we find "Nearest greater to left"
Output = "Nearest greater to left" index - i index)
*/
#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int arr[] = {100,80,60,70,60,75,85};
    int sz = sizeof(arr)/sizeof(arr[0]);

    vector<int> vec;
    vector<int> vecOutput;
    stack<pair<int, int>> st;
    for(int i=0; i<sz; i++)
    {

        if(st.size() == 0)
        {
            vec.push_back(-1);
        }
        else if(st.top().first > arr[i])
        {
            vec.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first <= arr[i])
        {
            while(st.size()>0 && st.top().first<= arr[i])
            {
                st.pop();
            }

            if(st.size() == 0)
            {
                vec.push_back(-1);
            }
            else{
                    vec.push_back(st.top().second);
            }
        }
        st.push({arr[i],i});
        vecOutput.push_back(i-vec[i]);
    }
    for(auto i : vecOutput)
    {
        cout<<i<<" ";
    }
    return 0;
}
