#include<bits/stdc++.h>
using namespace std;

void recursiveSelectionSort(vector<int>& v , int idx , int n)
{
    //base case
    if(idx == n)
        return;

    int mini = idx;
    for(int i = idx+1 ; i<n ; i++)
    {
        if(v[i] < v[mini])
        {
            mini = i;
        }
    }
    if(idx != mini)
        swap(v[mini],v[idx]);

    recursiveSelectionSort(v,idx+1,n);
}

void selectionSort(vector<int>& v)
{
    int n = v.size();
    int idx = 0;
    recursiveSelectionSort(v,idx,n);
}

int main()
{
    vector<int> v = {6,4,8,1,5,0,2,3};
    selectionSort(v);
    for(int val: v)
    {
        cout<<val<<" ";
    }
    return 0;
}