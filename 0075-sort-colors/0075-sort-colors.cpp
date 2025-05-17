class Solution {
public:
    void sortColors(vector<int>& nums) {
int n=nums.size();
//      for(int i=1;i<n;i++)
//      {
//         int j=i-1;
//         int temp=nums[i];
//        while(j>=0 && nums[j]>temp)  
//        {
//            nums[j+1]=nums[j];
//            j--;
//        }
//        nums[j+1]=temp;
//      }


      
//     }

int low=0;
int high=n-1;
int mid=low;
while(mid<=high)
{
    if(nums[mid]== 0)
    {
       swap(nums[low],nums[mid]);
        
        low++;
        mid++;
    }
    else if(nums[mid]==1)
    {
        mid++;
    }else
    {
        swap(nums[mid],nums[high]);
        high--;
    }
    
    

    
}
    }
};