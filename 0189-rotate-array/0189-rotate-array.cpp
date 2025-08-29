class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    //     int temp;
    //     int i;
        int n=nums.size();
        
        
       k=k%n;
    //     for(int t=0;t<k;t++)
    //     {
    //          temp=nums[nums.size()-1];
    //    for( i=nums.size()-1;i>0;i--) 
    //    {
        
    //     nums[i]=nums[i-1];

    //    }
    //    nums[0]=temp;

    //     }


    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
  for(int i=0;i<nums.size();i++) 
       {
        
   cout<<nums[i];
       }
        
        
    }
};