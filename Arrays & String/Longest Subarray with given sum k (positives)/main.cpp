#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& v, int k)
{
    int n = v.size();
    int ans = 0;
    for(int i = 0 ; i<n ; i++)
    {
        int sum = 0;
        for(int j = i ; j<n ; j++)
        {
            sum += v[j];
            if(sum == k)
            {
                ans = max(ans,j-i+1);
                break;
            }
            else if(sum > k)
                break;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3, 1, 1, 1, 1};
    int k = 5;
    int ans = subarraySum(v,k);
    cout<<ans;
    return 0;
}