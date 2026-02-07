class Solution {
public:
int t[301][5001];
int sol(vector<int>& coins,int i,int j){
if(j==0)
   return 1;
   if(i<=0) 
   return 0;
  if(t[i][j]!=-1)
  return t[i][j];

   if(coins[i-1]>j)
   {

    return t[i][j]= sol(coins,i-1,j);
   }

   int left=sol(coins,i,j-coins[i-1]);
   int right=sol(coins,i-1,j);
   return t[i][j]=left+right;
}
    int change(int amount, vector<int>& coins) {
   

        int n=coins.size();
        memset(t,-1,sizeof(t));
        return sol(coins,n,amount);
        
    }
};