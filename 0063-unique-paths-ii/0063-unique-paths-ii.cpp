class Solution {
public:
int t[101][101];
int sol(vector<vector<int>>& ob,int i,int j)
{
    if(i<0 || j<0)
    return 0;
    if(ob[i][j]==1)
    return 0;
    if(i==0 && j==0)
    return 1;
    

    
    if(t[i][j]!=-1)
    return t[i][j];
    int l=sol(ob,i,j-1);

    
    
   int r= sol(ob,i-1,j);
   return t[i][j]=l+r;

}
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {


       int n=ob.size();
       int m=ob[0].size();
       memset(t,-1,sizeof(t));
       return sol(ob,n-1,m-1);









    }
};