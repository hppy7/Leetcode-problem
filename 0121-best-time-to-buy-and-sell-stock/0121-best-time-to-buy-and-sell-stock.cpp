class Solution {
public:
    int maxProfit(vector<int>& nums) {
        
   int n=nums.size();
   int profit=0;
   int minbuy=nums[0];
   int ans=0;
   for(int i=1;i<n;i++)
   {
    profit=nums[i]-minbuy;
    ans=max(profit,ans);

    minbuy=min(nums[i],minbuy);


   }

return ans;
    }
};