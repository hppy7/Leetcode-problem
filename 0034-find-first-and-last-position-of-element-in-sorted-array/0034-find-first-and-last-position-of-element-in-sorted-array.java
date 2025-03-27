class Solution {
    public int[] searchRange(int[] nums, int target) {
       /*
        int[] n=new int[2];
        n[0]=-1;
        n[1]=-1;
    for(int i=0;i<nums.length;i++)  
    {
    if(nums[i]==target)
    {
     if(nums[i+1]==target)
     {
        n[0]=i+1;
        n[1]=i;
     }else
     {
        n[0]=i-1;
        n[1]=i;
     }

    }

    }
    return n;

    */

    int n[]=new int[2];
    n[0]=-1;
    n[1]=-1;

    for(int i=0;i<nums.length;i++)
    {
    if(nums[i]==target)
   { n[0]=i;
    break;
   }
    }
  if(n[0]==-1)
  return n;
    for(int i=nums.length-1;i>=0;i--)
    {
    if(nums[i]==target)
   {
   
    n[1]=i;
    break;
   }
    }
    return n;
    
/*
  if(nums.length==0)
  {
    return new int[] {-1,1-};
  }
  int low=0;
  int high=nums.length-1;
  while(low<high)
  {
  int mid=low+(high-low)/2;
  if(nums[mid]==target)
  {
    low=mid+1;
  }else
  {
    high=mid;
  }

  }

   if(nums[low]!=target)
   {
    return new int[] {-1,-1};
   }else
   {

    return new
   }*/


    }
}