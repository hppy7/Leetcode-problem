class Solution {
public:
    vector<vector<int>> ans;
    void func(int i,int n,vector<int>&nums,vector<int>&list){
        if(i==n) {
            ans.push_back(list);
            return;
        }
        list.push_back(nums[i]);
        func(i+1,n,nums,list);
        list.pop_back();
        func(i+1,n,nums,list);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>list;
        func(0,n,nums,list);
        return ans;
    }
};