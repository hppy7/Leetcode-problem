class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
    
        int o=original;
        int f=1;
        int c=nums.size();
        while(f){
        f=0;
        for(int i=0;i<c;i++)
        {
            if(nums[i]==o){
            o=o*2;
            f=1;
        
            }
        }
        }
      return o;  
    }
};