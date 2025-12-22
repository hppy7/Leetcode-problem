class Solution {
public:

vector<vector<int>> ans;

void sol(int s,int &n,int k,vector<int>& temp)
{


    if(k==0)
   {

    ans.push_back(temp);
    return;
   }
   if(s>n)
   return;
     temp.push_back(s);
     sol(s+1,n,k-1,temp);
      temp.pop_back();
    sol(s+1,n,k,temp);

}
    vector<vector<int>> combine(int n, int k) {

  vector<int> temp;
  sol(1,n,k,temp);

  return ans;
        
    }
};