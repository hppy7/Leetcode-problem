class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

int sum=0;

int n=nums.size();
vector<int> ans;
for(int i=0;i<n;i++)
{ sum=nums[i];
    for(int j=i+1;j<n;j++)
    {
        if(nums[i]+nums[j]==target)
        {
            ans.push_back(i);
            ans.push_back(j);

       return ans;

        }
    }
}
return {-1};
    }
};