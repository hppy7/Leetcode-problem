class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j;
        int t;





        
        vector<pair<int,int>> a;

        //sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int k=0;k<n;k++)
        {
            a.push_back({nums[k],k});
        }
        sort(a.begin(),a.end());
        j=n-1;
        while(i<j)
        {
          t=a[i].first+a[j].first; 
           if(t>target)
           {
            j--;
           }
           if(t<target)
           {
            i++;
           }
           if(t==target)
           {
            return {a[i].second,a[j].second};
           }
        }
        
    
    return {};
    }
};
