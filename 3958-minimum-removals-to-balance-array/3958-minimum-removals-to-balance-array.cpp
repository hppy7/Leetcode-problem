class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int bestRange = 1;
        int i = 0;

        for (int j = 0; j < n; j++) {

            // shrink start until range is valid
            while (nums[j] > 1LL * nums[i] * k) {
                i++;
            }

            int len = j - i + 1;
            bestRange = max(bestRange, len);
        }

        return n - bestRange;
    }
};
