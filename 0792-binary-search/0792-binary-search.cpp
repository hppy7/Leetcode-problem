class Solution {
public:
    int search(vector<int>& nums, int t) {
        
//   int ans=-1;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==t)
//             {
//                 ans=i;
//             }
//         }
//         return ans;
//     }

     int l=0;
     int r=nums.size()-1;
     int ans=-1;
     while(l<=r)
     {
        int mid=l+(r-l)/2;
         if(nums[mid]<t)
        {
            l=mid+1;
        }else if( nums[mid]>t)
        {
            r=mid-1;
        }

         if(nums[mid]==t)
        {
            ans=mid;
            break;
        }
     }

return ans;

    }
 };