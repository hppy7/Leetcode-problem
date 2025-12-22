class Solution {
public:

vector<vector<int>> ans;

void sol(int id,vector<int>& c ,int n,int t,vector<int>& temp)
{

    if(t==0)
    {

        ans.push_back(temp);
        return;
    }
   if(id>=n)
   {
    return;
   }
   if(c[id]<=t){
    temp.push_back(c[id]);
   sol(id,c,n,t-c[id],temp);
   temp.pop_back();
   }


   sol(id+1,c,n,t,temp);


}
    vector<vector<int>> combinationSum(vector<int>& candidates, int t) {

        int n=candidates.size();
        int id=0;
        vector<int> temp;
        sol(id,candidates,n,t,temp);

   return ans;
        
        
    }
};