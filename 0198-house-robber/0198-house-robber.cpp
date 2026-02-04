class Solution {
public:
int t[101];
int n;
int sol(vector<int>&nums,int i)
{

    if(i>=n)
    return 0;
    if(t[i]!=-1)
    return t[i];
    int left=nums[i]+sol(nums,i+2);
    int right=sol(nums,i+1);
    return t[i]= max(left,right);
}
    int rob(vector<int>& nums) {

      n=nums.size();
      memset(t,-1,sizeof(t));

     return sol(nums,0);

        
    }
};