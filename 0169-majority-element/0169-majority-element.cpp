class Solution {
public:
    int majorityElement(vector<int>& nums) {


       int n=nums.size();
       int half=n/2;
       int ans=0;

       for(int i=0;i<n;i++)
       {

            int c=nums[i];
            int P=0;
        for(int j=0;j<n;j++)
        {
          if(c==nums[j])
          {
            P++;
          }
        if(P>half)
        {   ans=nums[j];
            return ans;
        }
           
        }

       } 
       return ans;
    }
};