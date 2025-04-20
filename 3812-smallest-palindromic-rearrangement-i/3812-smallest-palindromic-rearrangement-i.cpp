class Solution {
public:
    string smallestPalindrome(string s) {
      vector<int> freq(26,0);
      for(auto c:s) 
      {
       freq[c-'a']++;
      } 
      string left="",mid="";
      string right="";
      for(int i=0;i<26;i++)
      {
        if(freq[i]%2==1)
        {
            mid=(char)(i + 'a');
        }
        for(int j=0;j<freq[i]/2;j++)
        {
            left+=(char)(i + 'a');
        }

        right=left;
        reverse(right.begin(),right.end());
        //return left+mid+right;
      }

       return left+mid+right; 

    }
};