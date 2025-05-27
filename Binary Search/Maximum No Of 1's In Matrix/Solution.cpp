#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int n , int key)
{
    int ans = n;
    int low = 0;
    int high = n-1;

    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] >= key)
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return n-ans;

}

int findMaximumOnes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int cnt_max = 0;
    int index = -1;

    for(int i = 0 ; i<n ; i++)
    {
        int cnt_ones = lowerBound(matrix[i],m,1);
        if(cnt_ones > cnt_max)
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

int main()
{
    vector<vector<int>> matrix = {{0,0,0},{0,0,0,},{0,0,0}};
    cout<<findMaximumOnes(matrix);
    return 0;
}