#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& v, int k)
{
    int n = v.size();
    int maxLen = 0;
    int sum = 0;
    map<int,int> prefix;
    for(int i = 0 ; i<n ; i++)
    {
        sum += v[i];
        if(sum == k)
            maxLen = i+1;

        int rem = sum-k;
        if(prefix.find(rem) != prefix.end())
        {
            maxLen = max(maxLen, i-prefix[rem]);
        }

        if(prefix.find(sum) == prefix.end())
            prefix[sum] = i;
    }
    return maxLen;
}

int main()
{
    vector<int> v = {2,0,-1,-5,5,0,5};
    int k = 5;
    int ans = subarraySum(v,k);
    cout<<ans;
    return 0;
}