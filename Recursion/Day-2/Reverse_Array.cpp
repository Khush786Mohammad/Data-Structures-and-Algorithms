#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void reverse(vector<int>&v , int l , int h)
{
    if(l >= h)
    return ;
    swap(v[l],v[h]);
    l++;
    h--;
    reverse(v,l,h);
}

void reverse2(vector<int>&v , int i)
{
    if(i >= v.size()/2)
    return ;

    swap(v[i],v[v.size()-1-i]);
    i++;
    reverse2(v,i);
}

int main()
{
    vector<int> v = {1,2,3,4,5,6};
    int low = 0;
    int high = v.size()-1;
    reverse(v,low,high);
    for(auto it : v)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    reverse2(v,0);
    for(auto it : v)
    {
        cout<<it<<" ";
    }
    return 0;
}