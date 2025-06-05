#include<bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int>& arr1, vector<int>& arr2)
{
    if(arr1.size() == 0)
        return arr2;
    if(arr2.size() == 0)
        return arr1;
    if(arr1.size() == 0 && arr2.size() == 0)
        return {};
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0;
    int j = 0;

    vector<int> unionArray;
    unionArray.push_back(min(arr1[0],arr2[0]));

    while(i<n1 && j<n2)
    {
        int size = unionArray.size();
        if(arr1[i] == arr2[j])
        {
            if(size > 0 && unionArray[size-1] != arr1[i])
            {
                unionArray.push_back(arr1[i]);
            }
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j])
        {
            if(size > 0 && unionArray[size-1] != arr1[i])
            {
                unionArray.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if(size > 0 && unionArray[size-1] != arr2[j])
            {
                unionArray.push_back(arr2[j]);
            }
            j++;
        }
        
    }

    while(i<n1)
    {
        int size = unionArray.size();
        if(size > 0 && unionArray[size-1] != arr1[i])
        {
            unionArray.push_back(arr1[i]);
        }
        i++;
    }

    while(j<n2)
    {
        int size = unionArray.size();
        if(size > 0 && unionArray[size-1] != arr2[j])
        {
            unionArray.push_back(arr2[j]);
        }
        j++;
    }
    return unionArray;
}

int main()
{
    vector<int> v1 = {3,4,6,7,9,9};
    vector<int> v2 = {1,5,7,8,8};

    vector<int> unionArray = findUnion(v1, v2);

    for(auto v : unionArray)
    {
        cout<<v<<" ";
    }
    return 0;
}