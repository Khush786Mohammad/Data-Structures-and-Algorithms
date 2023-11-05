#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr , int n , int target)
{
    int low = 0;
    int high = n-1;

    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == target)
        return mid;

        if(arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low += 1;
            high -= 1;
            continue;
        }

        if(arr[mid] >= arr[low])
        {
            if(arr[low] <= target && target <= arr[mid])
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        else{
            if(arr[mid] <= target && target <= arr[high])
            {
                low = mid + 1;
            }
            else{
                high = mid-1;
            }

        }
    }
    return -1;
}

int main()
{
    vector<int> v = {7,8,9,1,2,3,4,5,6};
    int n = v.size();
    int target = 4;

    int index = binarySearch(v,n,target);
    cout<<"Target element is present at: "<<index;
    return 0;
}