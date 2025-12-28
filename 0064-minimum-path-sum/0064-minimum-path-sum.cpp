class Solution {
public:
  int t[201][201];
 int sol(int i,int j,int m,int n,vector<vector<int >>& grid)
 {

   if(i<0 || i>n-1 || j<0 || j>m-1)
   return 1e9;
    if(i==n-1 && j==m-1)
    {

        return t[i][j]=grid[i][j];
    }

    if(t[i][j]!=-1)
    {
        return t[i][j];
    }
   int ans=min(sol(i,j+1,m,n,grid),sol(i+1,j,m,n,grid));
   return t[i][j]= grid[i][j] + ans;

 }
    int minPathSum(vector<vector<int>>& grid) {
       int  m=grid[0].size();
        int n=grid.size();
         memset(t,-1,sizeof(t));
       return sol(0,0,m,n,grid);
        
    }
};