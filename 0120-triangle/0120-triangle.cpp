class Solution {
public:
    int minimumTotal(vector<vector<int>>& tr) {


        int n=tr.size();
       vector<int> ans(tr[n-1].size());

        for(int i=0;i<tr[n-1].size();i++)
        {
         ans[i]=tr[n-1][i];
         
        }


        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<tr[i].size();j++)
            {

                ans[j]=tr[i][j]+min(ans[j],ans[j+1]);
            }
        }
        return ans[0];

        

        
    }
};