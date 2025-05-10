class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        

 int zero1=0,zero2=0;
long long sum1=0,sum2=0;
//  for(int i=0;i<nums1.size();i++)
//  {
//     if(nums1[i]==0 )
//     {
//     zero1++;
//     }
//  }

// for(int i=0;i<nums2.size();i++)
//  {
//     if(nums2[i]==0 )
//     {
//     zero2++;
//     }
//  }
for(int i=0;i<nums1.size();i++)
{
 sum1 += nums1[i] == 0 ? 1: nums1[i];
 zero1 +=nums1[i]==0? 1: 0;
  
}
 for(int i=0;i<nums2.size();i++)
 {
  sum2 +=nums2[i]==0?1:nums2[i];
  zero2 +=nums2[i]==0? 1: 0;
 }
 //int zero1=0,zero2=0;

//  for(int i=0;nums1.size();i++)
//  {
//     if(nums1[i]==0 )
//     {
//     zero1++;
//     }
//  }

// for(int i=0;nums1.size();i++)
//  {
//     if(nums1[i]==0 )
//     {
//     zero1++;
//     }
//  }


 if(sum1<sum2 && zero1==0 )
 return -1;
if(sum1>sum2 && zero2==0 )
 return -1;
  return max(sum1,sum2);
    }
};