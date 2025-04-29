#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& v, int k)
{
    map<int,int> prefix;
    int n = v.size();
    int maxLen = 0;
    int sum = 0;

    for(int i = 0 ; i<n ; i++)
    {
        sum += v[i];
        if(sum == k)
        {
            maxLen = i+1;
        }
        int rem = sum - k;
        if(prefix.find(rem) != prefix.end())
        {
            maxLen = max(maxLen, i-prefix[rem]);
        }
        prefix[sum] = i;
    }
    return maxLen;
}

int main()
{
    vector<int> v = {1, 2, 3, 1, 1, 1, 1};
    int k = 5;
    int ans = subarraySum(v,k);
    cout<<ans;
    return 0;
}