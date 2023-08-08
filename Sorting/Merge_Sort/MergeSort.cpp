#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &nums, int low , int mid , int high)
{
    int n = high-low+1;
    vector<int> temp(n);

    int i = low;
    int j = mid+1;

    int k = 0;

    while(i<=mid && j<=high)
    {
        if(nums[i] < nums[j])
        {
            temp[k] = nums[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = nums[j];
            j++;
            k++;
        }
    }

    while(i<=mid)
    {
        temp[k] = nums[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        temp[k] = nums[j];
        j++;
        k++;
    }

    for(int p=0,q=low; p<n ; p++,q++)
    {
        nums[q] = temp[p];
    }
}

void mergeSort(vector<int> &nums , int low , int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter vector elements\n";
    for(int i = 0 ; i<n ; i++)
    {
        cin>>nums[i];
    }

    int low = 0;
    int high = n-1;
    mergeSort(nums,low,high);

    cout<<"After Sorting\n";
    for(auto it : nums)
    {
        cout<<it<<" ";
    }
    return 0;
}