class Solution {
public:
    int dfs(int index, int currentXOR, vector<int>& nums) {
        if (index == nums.size()) {
            return currentXOR;
        }

        // Include nums[index] in the subset
        int include = dfs(index + 1, currentXOR ^ nums[index], nums);  // ✅ Passed nums

        // Exclude nums[index] from the subset
        int exclude = dfs(index + 1, currentXOR, nums);  // ✅ Passed nums

        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums) {
        return dfs(0, 0, nums);
    }
};
