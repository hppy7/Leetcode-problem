class Solution {
public:
    int maxProduct(vector<int>& nums) {

            int n=nums.size();
    //    sort(nums.begin(),nums.end(),greater<int>()) ;
    int max=nums[0];
    int min=0;
    for(int i=1;i<n;i++)
    {
        if(nums[i]>max)
        {
            min=max;
            max=nums[i];
            
        }else if(nums[i]>min)
        {
            min=nums[i];
        }
       
    }

    


    return (max-1)*(min-1);
   // return (nums[1]-1)*(nums[0]-1);


    }
};