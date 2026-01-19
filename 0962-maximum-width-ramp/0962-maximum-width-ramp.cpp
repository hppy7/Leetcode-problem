class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int n=nums.size();
        int ans=0;

        vector<int> rightmax(n);
        rightmax[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {

            rightmax[i]=max(nums[i],rightmax[i+1]);
        }
        int i=0;
        int j=0;

      while(j<n)
      {
       while(i<j && nums[i] > rightmax[j])
       {

        i++;
       }

       ans=max(ans,j-i);

       j++;

      }

        return ans;
        
    }
};