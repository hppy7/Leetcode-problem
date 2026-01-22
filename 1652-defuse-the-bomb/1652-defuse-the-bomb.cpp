class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();

        if (k == 0)
            return vector<int>(n, 0);

        vector<int> ans(n, 0);   // FIXED

        for (int i = 0; i < n; i++) {
            if (k > 0) {
                for (int j = 1; j <= k; j++) {
                    ans[i] += code[(i + j) % n];
                }
            } else {
                for (int j = 1; j <= abs(k); j++) {
                    ans[i] += code[(i - j + n) % n];
                }
            }
        }
        return ans;
    }
};
