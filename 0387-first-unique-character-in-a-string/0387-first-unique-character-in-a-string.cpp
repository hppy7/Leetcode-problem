class Solution {
public:
    int firstUniqChar(string s) {


        int fre[26]={0};
   int n=s.size();

        for(int i=0;i<n;i++)
        {

            fre[s[i]-'a']++;
        }
        

        for(int i=0;i<n;i++)
        {

              if(fre[s[i]-'a']==1)
              {
                return i;
              }
        }
        return -1;
    }
};