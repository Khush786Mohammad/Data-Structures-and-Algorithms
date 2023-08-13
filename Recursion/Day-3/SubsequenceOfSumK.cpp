#include<bits/stdc++.h>
using namespace std;

void subsequenceK(vector<int>&v , int k , int i , vector<int>&temp,vector<vector<int>> &ans , int sum)
{
    if(i>=v.size())
    {
        if(sum == k)
        {
            ans.push_back(temp);
        }
        return ;
    }
    temp.push_back(v[i]);
    sum+=v[i];
    //pick
    subsequenceK(v,k,i+1,temp,ans,sum);
    temp.pop_back();
    sum -= v[i];
    //not pick
    subsequenceK(v,k,i+1,temp,ans,sum);
}

int main()
{
    vector<int> v = {1,2,1};
    int k = 2;

    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;

    subsequenceK(v,k,0,temp,ans,sum);

    for(int i = 0 ; i<ans.size() ;i++)
    {
        for(int j = 0 ; j<ans[i].size() ; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}