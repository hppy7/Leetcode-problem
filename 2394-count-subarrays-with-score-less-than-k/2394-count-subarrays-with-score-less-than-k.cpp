class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

     int n=nums.size();
     long long left=0,right=0;
     long long sum=0;
     long long count=0;

     while(right<n)
     {
        sum+=nums[right];
    while((long long)sum*(right-left+1)>=k)
    {
    sum-=nums[left++];
    }
    
   count+=right-left+1;
   right++;
     
    }
     return count;
    }
}; 