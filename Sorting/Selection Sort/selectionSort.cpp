#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& v)
{
    int n = v.size();
    for(int i = 0 ; i<n ; i++)
    {
        int mini = i;
        for(int j = i+1 ; j<n ; j++)
        {
            if(v[j] < v[mini])
            {
                mini = j;
            }
        }
        if(i != mini)
            swap(v[i],v[mini]);
    }
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