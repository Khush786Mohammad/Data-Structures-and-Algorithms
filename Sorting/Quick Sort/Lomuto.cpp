#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>&nums , int lb , int ub)
{
    int pivot = nums[ub];
    int i = lb;

    for(int j = lb ; j<ub; j++)
    {
        if(nums[j] < pivot)
        {
            swap(nums[i],nums[j]);
            i++;
        }
    }
    swap(nums[ub],nums[i]);
    return i;
}

void quickSort(vector<int> &nums , int lb , int ub)
{
    if(lb<ub)
    {
        int loc = partition(nums,lb,ub);
        quickSort(nums,lb,loc-1);
        quickSort(nums,loc+1,ub);
    }
}

int main()
{
    int n ;
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the vector elements\n";
    for(int i = 0 ; i<n ; i++)
    cin>>nums[i];

    int low = 0;
    int high = n-1;
    quickSort(nums,low,high);

    for(auto it : nums)
    cout<<it<<" ";
    return 0;
}