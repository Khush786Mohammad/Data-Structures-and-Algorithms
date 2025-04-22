#include<bits/stdc++.h>
using namespace std;

void recursiveInsertionSort(vector<int>& v, int idx ,int n)
{
    //base case
    if(idx == n)
        return;

    int i = idx-1;
    int key = v[idx];

    while(i>=0 && key < v[i])
    {
        v[i+1] = v[i];
        i--;
    }
    v[i+1] = key;

    recursiveInsertionSort(v,idx+1,n);
}

void insertionSort(vector<int>& v)
{
    int n = v.size();
    int idx = 1;
    recursiveInsertionSort(v,idx,n);
}

int main()
{
    vector<int> v = {5,1,8,5,0,23,56,4};
    insertionSort(v);
    for(int val: v)
    {
        cout<<val<<" ";
    }
    return 0;
}