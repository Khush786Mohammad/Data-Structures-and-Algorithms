#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& v, int k)
{
    int n = v.size();
    int ptr1 = 0;
    int ptr2 = 0;
    int sum = 0;
    int maxLen = 0;

    while(ptr1 < n)
    {
        while(sum <= k)
        {
            sum += v[ptr1];
            if(sum == k)
            {
                maxLen = max(maxLen, ptr1-ptr2+1);
            }
            ptr1++;
        }
        while(sum > k)
        {
            sum -= v[ptr2];
            ptr2++;
        }
    }
    return maxLen;
}

int main()
{
    vector<int> v = {1, 2, 3, 1, 1, 1, 1};
    int k = 6;
    int ans = subarraySum(v,k);
    cout<<ans;
    return 0;
}