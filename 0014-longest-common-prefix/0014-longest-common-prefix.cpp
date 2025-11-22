class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(),strs.end());
        string f=strs[0];
        string l=strs.back();



             int j=0;
          while(j< f.size() && f[j]==l[j])
          {
               j++;
            }

            return f.substr(0,j);

//   int min=INT_MAX;
//   int max=INT_MIN;
//   string s1;
//   string s2;
//   int inn=0,in=0;
//        int n=strs.size();
//        for(int i=0;i<n;i++)
//        {
        
//         int s=strs[i].size();
        
//         if(s>max)
//         {
//          max=s; 
//          s1=strs[i];
//          inn=i;  
//         }
//         if(s<min)
//         {
//             min=s;
//             s2=strs[i];
//             in=i;
//         }
       

//        } 
//      int j=0;
//     while(j< strs[in].size() && strs[in][j]==strs[inn][j])
//     {
//         j++;
//     }

//     return strs[in].substr(0,j);

    }
};