class Solution {
public:
int m=1e9+7;
    int lengthAfterTransformations(string s, int t) {
     //unordered_map<char,int> mp;
      vector<int> mp(26,0);


        for(auto value : s) 
        {
         mp[value-'a']++;
        }
         for(int i=0;i<t;i++){
         //unordered_map<char ,int> newmap;
         vector<int> newmap(26,0);
         for(int i=0;i<26;i++)
         {
           
            char ch=i+'a';
            int f=mp[i];
            if(ch== 'z')
             {
                newmap['b'-'a']=(newmap['b'-'a']+f)% m;
                newmap['a'-'a']=(newmap['a'-'a']+f)% m;


            }else{

              newmap[(ch+1)-'a']=(newmap[(ch+1)-'a']+f)%m;
            }
            
          }

          mp=move(newmap);
         }
        // mp=move(newmap);
          int sum=0;
          for(int i=0;i<26;i++)
          {
            sum=(sum+mp[i])%m;
          }
          return sum;
    }
};