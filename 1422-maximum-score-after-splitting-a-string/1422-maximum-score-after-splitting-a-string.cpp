class Solution {
public:
    int maxScore(string s) {
       int n=s.size();
       int tones=0;
       for(int i=0;i<n;i++)
       {

        if(s[i]=='1')
        {
            tones++;
        }
       } 
       int ans=INT_MIN;
        int one=0,zero=0;
       for(int i=0;i<n-1;i++)
       {
        if(s[i]=='1')
          one++;
          else
           zero++;

            ans=max(ans,zero + (tones-one));

       
       } 
       return ans;
 
        
    }
};