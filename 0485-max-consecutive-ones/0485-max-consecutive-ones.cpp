class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

    
  int c=0;
  int ans=0;
    int n=nums.size();
    //  if(n==1&& nums[0]==1)
    //  ans=1;
      if(n==1&& nums[0]!=1)
      ans=0;
    for(int i=0;i<n;i++)
    {
     if(nums[i]==1)
     {
      c++;
        ans=max(ans,c);
    
     }else
     {  c=0;
     }
    }
    
   
    return ans;


    }
};