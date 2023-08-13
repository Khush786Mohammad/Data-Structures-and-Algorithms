#include<bits/stdc++.h>
using namespace std;

int subsequenceK(vector<int>&v , int k , int i , int sum)
{
    if(i>=v.size())
    {
        if(sum == k)
        {
            return 1;
        }
        return 0;
    }
    sum += v[i];
    int pick = subsequenceK(v,k,i+1,sum);
    sum -= v[i];
    int not_pick = subsequenceK(v,k,i+1,sum);
    return pick+not_pick;
}

int main()
{
    vector<int> v = {1,2,1,2,};
    int k = 2;

    int sum = 0;

    cout<< subsequenceK(v,k,0,sum);

    return 0;
}