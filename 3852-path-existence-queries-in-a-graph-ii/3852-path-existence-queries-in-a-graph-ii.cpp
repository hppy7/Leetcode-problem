#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // 1. Sort nodes by nums value
        vector<pair<int,int>> arr(n);
        for (int i = 0; i < n; i++) arr[i] = {nums[i], i};
        sort(arr.begin(), arr.end());

        vector<int> sortedVals(n), sortedIdx(n), idxMap(n);
        for (int i = 0; i < n; i++) {
            sortedVals[i] = arr[i].first;
            sortedIdx[i] = arr[i].second;
            idxMap[arr[i].second] = i; // original -> sorted index
        }

        // 2. Build jump[0] with two-pointer
        vector<int> jump0(n);
        int right = 0;
        for (int i = 0; i < n; i++) {
            while (right + 1 < n && sortedVals[right + 1] - sortedVals[i] <= maxDiff)
                right++;
            jump0[i] = right; // farthest reachable index from i in one edge
        }

        // 3. Binary lifting table
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        vector<vector<int>> jump(LOG, vector<int>(n));
        jump[0] = jump0;
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                jump[k][i] = jump[k-1][ jump[k-1][i] ];
            }
        }

        auto minJumps = [&](int start, int end) -> int {
            if (start == end) return 0;
            if (jump0[start] >= end) return 1;
            int res = 0;
            int cur = start;
            for (int k = LOG - 1; k >= 0; k--) {
                int nxt = jump[k][cur];
                if (nxt < end) {
                    res += (1 << k);
                    cur = nxt;
                }
            }
            if (jump0[cur] >= end) return res + 1;
            return -1;
        };

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            int u = q[0], v = q[1];
            int su = idxMap[u], sv = idxMap[v];
            int a = min(su, sv), b = max(su, sv);
            ans.push_back(minJumps(a, b));
        }
        return ans;
    }
};
