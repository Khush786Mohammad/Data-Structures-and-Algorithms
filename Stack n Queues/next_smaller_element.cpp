/*
eg [4,8,5,2,25] --> [2,5,2,-1,-1]

[13,7,6,12] --> [7,6,-1,-1]

*/


#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int>& nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n,-1);

    for(int i = n-1 ; i>=0 ; i--)
    {
        while(!st.empty() && nums[i] <= st.top())
        {
            st.pop();
        }
        if(!st.empty())
            ans[i] = st.top();

        st.push(nums[i]);
    }
    return ans;
}

int main()
{

    vector<int> nums = {13,7,6,12};
    vector<int> ans = nextSmaller(nums);

    for(auto a : ans)
        cout<<a<<" "<<endl;
    return 0;
}