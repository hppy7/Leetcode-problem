class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
  long long c=0;
 sort(nums.begin(),nums.end());
 int i=0;
 int j=nums.size()-1;
 while(i<j)
 {

    
    
        int sum=nums[i]+nums[j];
        if(sum <=upper)
        {
            c+=j-i;
            
           i++; 
        }
        if(sum>upper)
        {
            j--;
        }
        
    
 }
  i=0;
  long long t=0;
  j=nums.size()-1;
 while(i<j)
 {

    
    
        int sum=nums[i]+nums[j];
        if(sum <lower)
        {
            t+=j-i;
            
           i++; 
        }else
        {
            j--;
        }
        
    
 }
 long long ans=c-t;
   return ans;      
    }
};