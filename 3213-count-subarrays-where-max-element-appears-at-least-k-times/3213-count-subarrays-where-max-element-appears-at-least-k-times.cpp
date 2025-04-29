class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

      int ma=*max_element(nums.begin(), nums.end());
      int n=nums.size();

      int i=0;
      int j=0;
      long long result=0;
      int countmax=0;
      while(j<n)
      {
       if(nums[j]==ma)
       {
        countmax++;
       }
       while(countmax>=k)
       {
        result+=n-j;
        if(nums[i]==ma)
        {
            countmax--;
        }
       i++;
       }
       j++;

      }
       return result;
    }
};