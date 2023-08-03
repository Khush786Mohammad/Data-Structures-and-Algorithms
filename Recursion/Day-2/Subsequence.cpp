#include<bits/stdc++.h>
using namespace std;

void subSequence(vector<int>&v , int i , vector<vector<int>> &ans , vector<int> &sol , int n)
{
    if(i >= n)
    {
        ans.push_back(sol);
        return ;
    }
    sol.push_back(v[i]);
    subSequence(v,i+1,ans,sol,n);//take
    sol.pop_back();
    subSequence(v,i+1,ans,sol,n);//not take
}

int main()
{
    vector<int> v = {3,1,2};
    vector<vector<int>> ans;
    vector<int> sol;
    subSequence(v,0,ans,sol,v.size());
    cout<<ans.size()<<endl;

    for(int i = 0 ; i<ans.size();i++)
    {
        for(int j = 0 ; j<ans[i].size() ; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}