class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0;
        int curr = 1;
        int ans = 0;
        
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i-1]) {
                curr++;
            } else {
                ans += min(prev, curr);  // calculate first
                prev = curr;             // then update
                curr = 1;
            }
        }
        
        ans += min(prev, curr);  // very important (last group)
        return ans;
    }
};
