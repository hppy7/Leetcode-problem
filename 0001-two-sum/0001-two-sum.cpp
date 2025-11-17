class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//map<int,int>mp;
map<int, vector<int>> mp;
 int n=nums.size();
// for(int i=0;i<n;i++)
// {
//     int t=target-nums[i];
//     if(mp.find(t)!=mp.end())
//     {
//        return {i,mp[t]};

//     }
    

//     mp[nums[i]]=i;
// }


//     return {};   

for(int i=0;i<n;i++)
{
    mp[nums[i]].push_back(i);
}
sort(nums.begin(),nums.end());
int i=0,j=n-1;
while(i<j)
{
    int t=nums[i]+nums[j];
    
    if(t>target)
    {
        j--;
    }else if(t<target)
    {
        i++;
    }else
    {
        if(nums[i]==nums[j])
        {
            return {mp[nums[i]][0], mp[nums[i]][1]};
        }
      return {mp[nums[i]][0], mp[nums[j]][0]};
    }
    
}
return {};
    }
};