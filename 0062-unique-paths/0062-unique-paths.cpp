class Solution {
public:
   int t[101][101];
  int sol(int i,int j,int m ,int n)
  {


    if(i>m || i<0|| j>n || j<0)
    return 0;

    if(i==m-1 && j==n-1)
    {
        return 1;
    }


  if(t[i][j]!=-1)
  return t[i][j];
    int r= sol(i,j+1,m,n);
    int l= sol(i+1,j,m,n);
    return t[i][j]= r+l;
  }
    int uniquePaths(int m, int n) {

       memset(t,-1,sizeof(t));
        return sol(0,0,m,n);
        
    }
};