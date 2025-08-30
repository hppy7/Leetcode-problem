class Solution {
public:
    int singleNumber(vector<int>& nums) {
       
        sort(nums.begin(),nums.end());
         int ans=nums[nums.size()-1];
        for(int i=0;i<nums.size()-1;i++)
        {
                if(nums[i]==nums[i+1])
                {
                    i++;
                    continue;

                }else
                {
                    ans=nums[i];
                    break;
                }
        }
        return ans;
    }
};