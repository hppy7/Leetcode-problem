class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        

unordered_map<string,int> mp;
int result=0;

for(string &word: words)
{
    string reverseword=word;
    swap(reverseword[0],reverseword[1]);
    if(mp[reverseword]>0)
    {
        result +=4;
        mp[reverseword]--;
    }else
    {
        mp[word]++;
    }
}

   for(auto &it : mp)
   {
    string word=it.first;
    int count=it.second;
    if(word[0]==word[1]&& count> 0)
    {
        result +=2;
        break;
    }
   }
return result;
    }
};