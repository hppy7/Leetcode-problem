class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {

    int n=nums.size();
    long long sum=0;
     int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
       sum+=nums[i];
       mx=max(mx,nums[i]);
    }
   int s=1;
   int e=mx;
   int ans;
   // sort(nums.begin(),nums.end());
   while(s<=e)
{
        int mid=s+(e-s)/2;
        long long c=0;
        
 
        
        for(int i=0;i<n;i++)
        {
             
             
                int u=nums[i]/mid;
               c=c+u;
               if(nums[i]%mid)
               {
                c++;
               }

             
        }
        if(c>h)
        {
            
            s=mid+1;
        }else
        {
            ans=mid;
            e=mid-1;
        }
}return ans;
    }
};