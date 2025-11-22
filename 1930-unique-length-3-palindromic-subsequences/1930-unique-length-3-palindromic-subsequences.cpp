class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        int count=0;

        for(int i=0;i<s.length();i++)
        {
            int idx=s[i]-'a';
            if(first[idx]==-1)
                first[idx]=i;
            last[idx]=i;
        }

        for(int idx=0;idx<26;idx++)
        {
            if(first[idx]!=-1 && first[idx]!=last[idx])
            {
                set<char>st;
                for(int i=first[idx]+1;i<=last[idx]-1;i++)
                {
                    st.insert(s[i]);
                }
                count+=(st.size());
            }
        }
        return count;
    }
};