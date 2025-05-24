class Solution {
public:

    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        auto lambda=[x](char ch)
        {
         return (ch==x);
        };
     for(int i=0;i<words.size();i++)
     {

        if(any_of(words[i].begin(),words[i].end(),lambda)==true)
        ans.push_back(i);
     }
    // for(int i=0;i<ans.size();i++)
    // {
    //     cout<<ans[i]<<",";
    // }
return ans;

    }
};