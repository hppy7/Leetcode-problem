class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
       if(k>n)
       return -1;
        int mx=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            mx=max(mx,nums[i]);
        }

        int s=mx;
        int e=sum;
        while(s<=e)
        {

            int mid=s+(e-s)/2;
            int pages=0;
            int c=1;
            for(int i=0;i<n;i++)
            {
             pages+=nums[i];
             if(pages>mid)
             {
                c++;
                pages=nums[i];
             }
            }
            if(c<=k)
            {  ans=mid;
                e=mid-1;
            }else
            {
                s=mid+1;
            }
        }

        return ans;
    }
};