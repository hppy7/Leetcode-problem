class Solution {
public:
int t[101][101];
int sol(vector<vector<int>>& mat,int n,int me)
 {

vector<int> ans=mat[n-1];

for(int i=n-2;i>=0;i--)
{ vector<int> ans1(n);
    for(int j=0;j<n;j++)
    {
            int r=INT_MAX;
        if(j<n-1)
        {
             r=mat[i][j]+ans[j+1];
        }
        int mmm=mat[i][j]+ans[j];
        int l;
        if(j>0)
        {
            l=mat[i][j]+ans[j-1];
        }else
        {
            l=INT_MAX;
        }
        ans1[j]=min({mmm,r,l});
     

    }
ans=ans1;

}


    int mm=INT_MAX;
        for(int i=0;i<n;i++)
        {
          if(ans[i]<mm)
          {
            mm=ans[i];
          }
        }
        return mm; 


//     if(j>=mat[0].size() || j<0)
//     return INT_MAX;
//  if(i==mat.size()-1)
//  return mat[i][j];
 
//  if(t[i][j]!=-1)
//  return t[i][j];

//  int l=sol(mat,i+1,j-1);
//  int r=sol(mat,i+1,j+1);
//  int m=sol(mat,i+1,j);
//  return t[i][j]=mat[i][j] + min({l,r,m});

}
    int minFallingPathSum(vector<vector<int>>& mat) {


     int n=mat.size();
    // memset(t,-1,sizeof(t));
//     // int ans = INT_MAX;
//    for (int j = 0; j < n; j++) {
// //     ans = min(ans, sol(mat, 0, j));
// }
return sol(mat,n,n);


        
    }
};