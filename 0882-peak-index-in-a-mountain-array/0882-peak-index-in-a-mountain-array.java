class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        /*
        int max=arr[0];
        int c=0;
    for(int i=0;i<arr.length;i++) 
    {
     if(arr[i]>max)
     {
        max=arr[i];
        c=i;
     }

    }
    return c;   
    */
/*
    for(int i=1; i<arr.length;i++)
    {
        if(arr[i]>arr[i+1])
        {
            return i;
        }
    }
    return 0;
    */

    int low=0, high=arr.length-1;
    while(low<high)
    {
      int mid=low +(high-low)/2;
     if(arr[mid]<arr[mid+1]) 
     {
     low=mid+1;

     }else
     {
        high=mid;
     }

    }
    return low;
    }
}