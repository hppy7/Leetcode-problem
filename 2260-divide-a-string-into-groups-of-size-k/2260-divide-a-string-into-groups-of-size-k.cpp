class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
  vector<string> ans;
       int j=0;
        int i=0;
        int n=s.size();
         cout<<"[";
         while(j<n)
         {
             string p="";
       for(i=0;i<k;i++)
       {
        //cout<<"\"";
       // cout<<s[i];
    //    
      //string p="";
      if(j<s.size())
      {
        p+=s[j++];
      }else
      {
        p+=fill;
      }
       }
    ans.push_back(p);
       }
    // cout<<"[";
    //   for(int j=0;j<ans.size();j++)
    //   {
    //        cout<<"\"";
    //        cout<<s[i];
    //        cout<<"\"";
    //        if(i!=ans.size()-1)
    //        cout<<",";
    //   }
    
       return ans; 
    }
};