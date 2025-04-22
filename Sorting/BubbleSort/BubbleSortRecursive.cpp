#include<bits/stdc++.h>
using namespace std;

void bubbleSortRecursive(vector<int>& v , int idx , int n)
{
    if(idx == n-1)
        return;

    for(int i = idx+1 ; i<n ; i++)
    {
        if(v[i] < v[idx])
        {
            swap(v[i],v[idx]);
        }
    }
    bubbleSortRecursive(v,idx+1,n);
}

void bubbleSort(vector<int>& v)
{
    int n = v.size();
    int idx = 0;
    bubbleSortRecursive(v,idx,n);
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