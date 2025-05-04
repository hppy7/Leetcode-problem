class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& nums) {
    
      map<pair<int,int>,int> mp;

      for(auto& d : nums) 
      {
        if(d[0]>d[1])
        {
            swap(d[0],d[1]);
        }
        mp[{d[0],d[1]}]++;
      } 
      int result =0;
      for(auto &it : mp)
      {
        int freq=it.second;
        result+=freq*(freq-1)/2;
      }
      return result; 
    }
};










// class Solution {
// public:
//     int numEquivDominoPairs(vector<vector<int>>& nums) {
//         int c=0;
//       for(int i=0;i<nums.size()-1;i++)
//       {
       
//            for(int j=i+1;j<nums.size();j++)
//            {
//             int a=nums[i][0];
//             int b=nums[i][1];
//             int c1=nums[j][0];
//             int d=nums[j][1];
//             if((a==c1 && b== d)|| (a==d && b==c1))
//             {
//                 c++;
//             }
//            }
//       }  
//       return c; 
//     }
// };