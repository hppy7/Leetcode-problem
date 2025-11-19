class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    int n=nums.size();
     int a;
    int ans=INT_MAX;
    sort(nums.begin(),nums.end());
    for(int k=0;k<n;k++)
    {

       int i=k+1;
       int j=n-1;
        while(i<j)
        {
           int sum= nums[i]+nums[j]+nums[k];
           if(sum>target)
           {
            j--;
           }else if(sum<target)
           {

            i++;
           }else
           {
            return sum;
           }
            int  ans1=abs(target-sum);
             if(ans1<ans)
             {
              a=sum;
              ans=ans1;
             }


        }

    }
    return a;


    }
};