class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {


        int n=g.size();
        int n1=s.size();

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
          int i=n-1,j=n1-1;
          int c=0;
        while(j>=0 && i>= 0)
        {
           if(s[j]>=g[i]){
           c++;
           i--;
           j--;
           }else if(s[j]<g[i])
           {
           i--;
           }else
           {
            j--;
           }


        }
        
    return c;
    }
};