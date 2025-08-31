class Solution {
public:
    int search(vector<int>& nums, int t) {
        
  int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==t)
            {
                ans=i;
            }
        }
        return ans;
    }
};