class Solution {
public:
    int maxSubArray(vector<int>& nums) {



       int n=nums.size();
       int presum=0;
       int ans=INT_MIN;
       for(int i=0;i<n;i++)
       {
         presum+=nums[i];
         ans=max(ans,presum);
         if(presum<0)
         {
            presum=0;
         }


       } 
       return ans;
    }
};