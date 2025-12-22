class Solution {
public:
    bool makeEqual(vector<string>& words) {

  int n=words.size();


        int fre[26]={0};
        for(int i=0;i<n;i++)
        {
              string ch=words[i];

              for(char chh : ch){
             
              fre[chh-'a']++;
              }
            
        }

        for(int i=0;i<26;i++)
        {

            if(fre[i]!=0)
            {
                int ans=fre[i]%n;

                if(ans!=0)
                return false;
            }
        }


   return true;
        
    }
};