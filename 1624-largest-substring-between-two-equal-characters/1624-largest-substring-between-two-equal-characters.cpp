class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {


        int n=s.size();
   int ans=-1;
        map<char,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]=i;
        }

        for(int i=0;i<n;i++)
        {

            char ch=s[i];
            int in=mp[s[i]];

            if(in>i)
            ans=max(ans,in-i-1);
            
        }

        
        return ans; 
        
    }
};