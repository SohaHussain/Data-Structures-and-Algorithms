// pivot element in an array

 int pivot(vector<int> arr)
    {
        int start = 0;
        int end = arr.size()-1;
        int mid;
        
        while(start<=end)
        {
            mid = start + (end-start)/2;
            if(mid<end && arr[mid]>arr[mid+1])
                return mid;
            if(mid > start && arr[mid]<arr[mid-1])
                return mid-1;
            if(arr[start]>=arr[mid])
                end = mid-1;
            else if(arr[start]<arr[mid])
                start = mid+1;
        }
        return -1;
    }
