class Solution {
public:
    int binaryGap(int n) {
        
  string s;
        while(n>0)
        {
            s+=n%2+'0';

   
            n/=2;
        }
 int i=0,j=-1;
 int ans=0;
        while(i<s.size())
        {

            if(s[i]=='1')
            {  if(j!=-1)
             ans=max(ans,i-j);
             j=i;
            }
            i++;
        }
        return ans;
    }
};