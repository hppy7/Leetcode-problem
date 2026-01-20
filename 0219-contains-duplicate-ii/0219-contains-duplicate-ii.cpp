class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n=nums.size();
     



     unordered_set<int> st;

     for(int i=0;i<n;i++)
     {
   

   if(i>k)
   {

    st.erase(nums[i-k-1]);
   }

     if(st.count(nums[i]))
     {
        return true;
     }

        st.insert(nums[i]);
     }
  return false;
    }
};