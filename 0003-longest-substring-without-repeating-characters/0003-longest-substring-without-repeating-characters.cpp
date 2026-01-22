class Solution {
public:
    int lengthOfLongestSubstring(string s) {

     int n=s.size();
  int  ans=0;
     set<char> st;
  int l=0;
     for(int i=0;i<n;i++)
     {

        while(st.find(s[i])!=st.end())
        {
            int a=st.size();
            ans=max(ans,a);
            st.erase(s[l++]);
            

        }
        st.insert(s[i]);
        ans=max(ans,int(st.size()));

     }
     return ans;

        
    }
};