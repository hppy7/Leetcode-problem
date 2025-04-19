class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int c=0;
        int i=0;
        sort(nums.begin(),nums.end());
        int j=nums.size()-1;
        while(i<j)
        {    int sum=nums[i]+nums[j];
            if(sum<target)
            {
                c+=j-i;
                i++;
            }
            else
            {
                j--;
            }
        }
       return c; 
    }
};