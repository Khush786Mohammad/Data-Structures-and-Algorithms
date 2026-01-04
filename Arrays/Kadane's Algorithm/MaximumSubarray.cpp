#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> maximumSubarray(vector<int>& nums)
{
    int n = nums.size();
    int maxi = INT_MIN;
    int sum = 0;
    int start = 0;
    int low = -1;
    int high = -1;

    for(int i = 0 ; i<n ; i++)
    {
        if(sum == 0)
            start = i;

        sum += nums[i];

        if(sum > maxi)
        {
            maxi = sum;
            low = start;
            high = i;
        }

        if(sum < 0)
            sum = 0;
    }
    return {{maxi},{low,high}};
}
int main()
{
    vector<int> nums = {-2,-3,4,-1,-2,1,5,-3};
    vector<vector<int>> ans = maximumSubarray(nums);
    cout<<"Maximum Subarray sum is :"<<ans[0][0]<<endl;
    cout<<"Maxium subarray is:"<<endl;
    for(int i = ans[1][0] ; i<= ans[1][1]; i++)
    {
        cout<<nums[i]<<" ";
    }
    
    return 0;
}