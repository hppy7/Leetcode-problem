class Solution {
public:
    void moveZeroes(vector<int>& nums) {
int n=nums.size();
       
    //     for(int j=0;j<n;j++)
    //     {
    //      if(nums[j]==0)
    //      {  int i;
    //         for( i=j;i<n-1;i++)
    //         {

    
    //          nums[i]=nums[i+1];
    //         }
    //         nums[i]=0;
    //         j--;
    //      }
       
    //     }
    int m=n-1;
    int pos=0;
        for(int i=0;i<n;i++)
    {   
        if(nums[i]!=0)
        {
            nums[pos++]=nums[i];

        }
    }
    while(pos<n)
    {
      nums[pos++]=0;
    }
          
       
    }
};