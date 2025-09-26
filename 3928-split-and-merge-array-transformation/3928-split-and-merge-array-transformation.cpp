
class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        if (nums1 == nums2) return 0;
        int n = nums1.size();

        queue<pair<vector<int>, int>> q;
        set<vector<int>> visited;
        q.push({nums1, 0});
        visited.insert(nums1);

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            vector<int> state = cur.first;
            int moves = cur.second;

            for (int L = 0; L < n; ++L) {
                for (int R = L; R < n; ++R) {
                    // subarray to move
                    vector<int> sub(state.begin() + L, state.begin() + R + 1);

                    // remainder after removing sub
                    vector<int> rem;
                    rem.insert(rem.end(), state.begin(), state.begin() + L);
                    rem.insert(rem.end(), state.begin() + R + 1, state.end());

                    // insert sub at every possible position in rem
                    for (int i = 0; i <= (int)rem.size(); ++i) {
                        // inserting back at same original position is a no-op
                        if (i == L) continue;

                        vector<int> new_state;
                        new_state.reserve(n);
                        new_state.insert(new_state.end(), rem.begin(), rem.begin() + i);
                        new_state.insert(new_state.end(), sub.begin(), sub.end());
                        new_state.insert(new_state.end(), rem.begin() + i, rem.end());

                        if (visited.insert(new_state).second) {
                            if (new_state == nums2) return moves + 1;
                            q.push({new_state, moves + 1});
                        }
                    }
                }
            }
        }

        return -1; // unreachable for valid inputs
    }
};
