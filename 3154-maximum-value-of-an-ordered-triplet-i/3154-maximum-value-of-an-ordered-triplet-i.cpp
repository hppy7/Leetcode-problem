class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxval=0;
        //int a=-1,b=-1,c=-1;
        int n=nums.size();
      for(int i=0;i<n;i++)   
      {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
              //long long val=(long long)(nums[i]-nums[j])*nums[k];
              long long sum=(long long)(nums[i]-nums[j])*nums[k];
              if(sum>maxval){
               maxval=sum;
              }
            }

        }
      }
        
      return maxval;
    }
};