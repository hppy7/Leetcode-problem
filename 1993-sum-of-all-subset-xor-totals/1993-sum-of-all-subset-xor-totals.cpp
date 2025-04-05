class Solution {
public:
    int dfs(int index, int currentXOR, vector<int>& nums) {
        if (index == nums.size()) {
            return currentXOR;
        }

        
        int include = dfs(index + 1, currentXOR ^ nums[index], nums);  

        
        int exclude = dfs(index + 1, currentXOR, nums);  

        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums) {
        return dfs(0, 0, nums);
    }
};
