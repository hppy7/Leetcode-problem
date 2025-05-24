class Solution {
    public int[][] transpose(int[][] matrix) {
  int c=matrix[0].length;  // column size
  int r=matrix.length;  //row size 

   int[][] mat=new int[c][r];
   for(int i=0;i<r;i++)
   {
      for(int j=0;j<c;j++)
      {
      mat[j][i]=matrix[i][j];

      }

      
   }

  return mat;
    }
}