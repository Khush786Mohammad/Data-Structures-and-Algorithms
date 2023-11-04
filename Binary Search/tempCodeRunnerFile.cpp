int low = 0;
    int high = n-1;
    int pos = -1;

    while(low <=high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] >= x)
        {
            pos = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return pos;