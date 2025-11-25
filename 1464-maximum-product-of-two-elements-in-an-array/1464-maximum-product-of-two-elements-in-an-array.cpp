class Solution {
public:
    int maxProduct(vector<int>& nums) {

       int n=nums.size();
       sort(nums.begin(),nums.end(),greater<int>()) ;
      return (nums[1]-1)*(nums[0]-1);
    }
};