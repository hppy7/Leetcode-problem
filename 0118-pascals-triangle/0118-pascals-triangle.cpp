class Solution {
public:
 vector<vector<int>> ans;
 
 
    vector<vector<int>> generate(int n) {


     

       for(int i=0;i<n;i++)
       {
                vector<int> ans1(i+1,1);
                for(int j=1;j<i;j++)
                {
                   ans1[j]=ans[i-1][j-1]+ans[i-1][j];
                }
                ans.push_back(ans1);
        
       }
        
     return ans;


        
    }
};