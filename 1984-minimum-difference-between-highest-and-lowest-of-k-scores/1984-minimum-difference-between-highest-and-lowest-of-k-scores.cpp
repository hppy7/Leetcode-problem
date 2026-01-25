class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();

        
        sort(nums.begin(),nums.end());

        if(k==0)
        return 0;
        int j=k-1;
         int ans=INT_MAX;
        for(int i=0;(i+k-1)<n;i++)
        {
             int diff=nums[i+k-1]-nums[i];

              ans=min(ans,diff);

        }

        return ans;
        
    }
};