#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& v)
{
    int n = v.size();
    for(int i = 1 ; i<n ; i++)
    {
        int j = i-1;
        int key = v[i];

        while(j>=0 && key < v[j])
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
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