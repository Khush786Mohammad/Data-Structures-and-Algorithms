#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& v)
{
    int n = v.size();
    for(int i = 0 ; i<n-1 ; i++)
    {
        bool flag = true;
        for(int j = i+1 ; j<n ; j++)
        {
            if(v[j] < v[i])
            {
                flag = false;
                swap(v[j],v[i]);
            }
        }
        if(flag)
            break;
    }
    return ;
}

int main()
{
    vector<int> v = {5,1,8,5,0,23,56,4};
    bubbleSort(v);
    for(int val: v)
    {
        cout<<val<<" ";
    }
    return 0;
}