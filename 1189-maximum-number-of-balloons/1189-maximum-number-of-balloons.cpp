class Solution {
public:
    int maxNumberOfBalloons(string text) {

        int n=text.size();
   vector<int> freq(26,0);

        for(int i=0;i<n;i++)
        {
          freq[text[i]-'a']++;

        }



        int c=min({
            freq['b'-'a'],
             freq['a'-'a'],
              freq['l'-'a']/2,
               freq['o'-'a']/2,
                freq['n'-'a']
    });
        return c;
        
        
    }
};