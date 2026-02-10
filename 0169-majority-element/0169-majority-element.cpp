class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
         int n=nums.size();
        unordered_map<int ,int> mp;
        for(int i=0;i<n;i++)
        {
           mp[nums[i]]++;

        }
           int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
           if(mp[nums[i]] > mp[ans])
            {
                ans = nums[i];
            }
        }
        return ans;
    }
};