class Solution {
public:
    string destCity(vector<vector<string>>& path) {
       unordered_map<string,int> mp;
       for(auto &paths : path)
       {

        string source=paths[0];
        mp[source]=1;
       }
       for(auto &paths : path)
       {

        string dest=paths[1];
        if(mp[dest]!=1)
        {

            return dest;
        }
       }
  return "";
    }
};