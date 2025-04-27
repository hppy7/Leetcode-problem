class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int c=0;
      for(int i=0;i<nums.size()-2;i++)
      {
        int y=2*(nums[i]+nums[i+2]);
     if(y==nums[i+1])
     {
        c++;
     }
      }  
      return c;
    }
};