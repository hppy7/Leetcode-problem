class Solution {
public:
    vector<bool> pathExistenceQueries(int n,
                                      vector<int>& nums,
                                      int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> comp(n);
        int currComp = 0;
        comp[0] = currComp;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff)
                ++currComp;
            comp[i] = currComp;
        }
        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            int u = q[0], v = q[1];
            ans.push_back(comp[u] == comp[v]);
        }
        return ans;
    }
};
