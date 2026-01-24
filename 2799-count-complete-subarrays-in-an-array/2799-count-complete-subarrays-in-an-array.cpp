class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {



       
    int ans=0;

        int j=0;

        set<int> st(nums.begin(),nums.end());
        int c=st.size();
        int n=nums.size();
      unordered_map<int,int> ump;
        for(int i=0;i<n;i++)
        {

              ump[nums[i]]++;

          
          while(ump.size()==c)
          {
              
           ans+=n-i;

           
           ump[nums[j]]--;
           if(ump[nums[j]]==0)
           {
            ump.erase(nums[j]);
           }
           j++;
           

          }
        



        }

        return ans;
        
    }
};