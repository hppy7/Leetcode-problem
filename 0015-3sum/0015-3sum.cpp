class Solution {
public:
 vector<vector<int>> ans;
 void twosum(vector<int>& nums,int k,int j,int t)
 {
    while(k<j)
    {
     
        if(nums[k]+nums[j]==t)
        {


    
            ans.push_back({-t,nums[k],nums[j]});
            k++;
          j--;
      while(k<j && nums[k]==nums[k-1])
     k++;
     while(k<j && nums[j]==nums[j+1])
     j--;

        }else if(nums[k]+nums[j] < t)
        {
          k++;
        }else
        {
            j--;
        }
    }
 }
    vector<vector<int>> threeSum(vector<int>& nums) {
  int n=nums.size();

      map<int,int> mp;
      //vector<vector<int>> ans
      if(n<3)
      {
        return {};
      }
      sort(nums.begin(),nums.end());

      for(int i=0;i<n;i++) 
      {  
        

     if(i>0 && nums[i]==nums[i-1])
     continue;


       int n1=nums[i];
       int t=-n1;
       int j=n-1;
       twosum(nums,i+1,j,t);

        

      } 
      return ans;
    }
};