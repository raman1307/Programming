#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;
vector<int> leftIndex;
vector<int> rightIndex;
void NearestSmallerToRight(int arr[], int sz, vector<int> &vec)
{
    stack<pair<int, int>> st;
    int sudoIndex = sz;

    for(int i=sz-1; i>=0; i--)
    {
        if(st.size() == 0)
        {
            vec.push_back(sudoIndex);
        }
        else if(st.top().first < arr[i])
        {
            vec.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first >= arr[i])
        {
            while(st.size()>0 && st.top().first>= arr[i])
            {
                st.pop();
            }

            if(st.size() == 0)
            {
                vec.push_back(sudoIndex);
            }
            else{
                vec.push_back(st.top().second);
            }
        }
        st.push({arr[i],i});

    }
    reverse(vec.begin(), vec.end());
    for(auto i:vec)
    {
        cout<<"Right"<<" : "<<i<<endl;
    }
}
void NearestSmallerToLeft(int arr[], int sz, vector<int> &vec)
{
    stack<pair<int, int>> st;

    int sudoIndex = -1;

    for(int i=0; i<sz; i++)
    {
        if(st.size() == 0)
        {
            vec.push_back(sudoIndex);
        }
        else if(st.top().first < arr[i])
        {
            vec.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first >= arr[i])
        {
            while(st.size()>0 && st.top().first>= arr[i])
            {
                st.pop();
            }

            if(st.size() == 0)
            {
                vec.push_back(sudoIndex);
            }
            else{
                    vec.push_back(st.top().second);
            }
        }
        st.push({arr[i],i});

    }

    for(auto i:vec)
    {
        cout<<"Left"<<" : "<<i<<endl;
    }
}

int MaximumArea(int arr[], int sz)
{
    int maxArea = 0;
    for(int i=0; i<sz; i++)
    {
        if(arr[i] > maxArea)
        {
            maxArea=arr[i];
        }
    }
    return maxArea;
}
int MaximumAreaHistogram(int arr[], int sz)
{

    vector<int> rightIndex;
    vector<int> leftIndex;
    int arrWidth[sz];
    int area[sz];
    NearestSmallerToRight(arr,sz,rightIndex);
    NearestSmallerToLeft(arr, sz,leftIndex);

    for(int j=0; j<sz; j++)
    {
        arrWidth[j] = rightIndex[j] - leftIndex[j] - 1;
    }

    //Area of Histogram
    for(int i=0; i<sz;  i++)
    {
        area[i] = arr[i]*arrWidth[i];
    }
    cout<<"Maximum Area : "<<MaximumArea(area,sz);
    return MaximumArea(area, sz);
}
int main()
{
    int arr[] = {6,4,5,4,5,1,6};

    int sz = sizeof(arr)/sizeof(arr[0]);
    MaximumAreaHistogram(arr, sz);

    return 0;
}
