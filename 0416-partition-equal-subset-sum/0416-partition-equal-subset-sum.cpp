class Solution {
public:
int t[201][20000];
bool sol(vector<int>& nums,int j,int i)
{
 if(j==0)
 return true;
 if(i==0)
 return false;
 if(t[i][j]!=-1)
 return t[i][j];
 if(nums[i-1]<=j)
 {
    return t[i][j]=sol(nums,j-nums[i-1],i-1) || sol(nums,j,i-1);
 }else
 {
    return t[i][j]=sol(nums,j,i-1);
 }

}
    bool canPartition(vector<int>& nums) {



       int sum=accumulate(nums.begin(),nums.end(),0);
     if (sum % 2 != 0) return false;


       sum/=2;
memset(t,-1,sizeof(t));
      return  sol(nums,sum,nums.size()); 
    }
};