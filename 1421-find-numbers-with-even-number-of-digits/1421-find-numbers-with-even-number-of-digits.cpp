class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size();i++) 
        {
           int l=to_string(nums[i]).length();
           if(l%2==0)
           c++;
        

        }
     return c;
    }
};