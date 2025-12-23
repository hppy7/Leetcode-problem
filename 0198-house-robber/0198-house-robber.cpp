class Solution {
public:
int t[101];
int sol(vector<int>& nums,int i,int n)
{

    if(i>=n)
    {
        return 0;
    }

    if(t[i]!=-1)
    return t[i];

    int steal=nums[i]+sol(nums,i+2,n);
    int skip= sol(nums,i+1,n);
    return t[i]=max(steal,skip);
}
    int rob(vector<int>& nums) {



      memset(t,-1,sizeof(t));
      int n=nums.size();
      return sol(nums,0,n);
    }
};