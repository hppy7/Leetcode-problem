class Solution {
public:
  int t[101];
int sol(vector<int>& nums,int i,int nn)
{


    if(i>nn)
    {
        return 0;
    }
   if(t[i]!=-1)
   {
    return t[i];
   }
    int steal=nums[i]+sol(nums,i+2,nn);
    int skip= sol(nums,i+1,nn);
    return t[i]=max(steal,skip);
}
    int rob(vector<int>& nums) {




      int n=nums.size();
      if(n==1)
      return nums[0];
        memset(t,-1,sizeof(t));
      int one=sol(nums,0,n-2);
        memset(t,-1,sizeof(t));
      int two=sol(nums,1,n-1);

      return t[n]= max(one,two);
    }
};