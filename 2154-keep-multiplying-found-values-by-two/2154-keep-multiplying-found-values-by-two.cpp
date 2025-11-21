class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
    
        int o=original;
        sort(nums.begin(),nums.end());
        int c=nums.size();
        
        for(int i=0;i<c;i++)
        {
            if(nums[i]==o){
            o=o*2;
        
        
            }
        }
        
      return o;  
    }
};