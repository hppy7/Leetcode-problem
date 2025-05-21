class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();        // number of rows
        int m = matrix[0].size();

          vector<vector<int>> mat2(n,vector<int>(m));
      for(int i=0;i<n;i++)
     {
          for(int j=0;j<m;j++)
          {
            mat2[i][j]=matrix[i][j];
          }
          
          
          }


     for(int i=0;i<n;i++)
     {
          for(int j=0;j<m;j++)
          {

            if(matrix[i][j]==0)
            {
             for(int k=0;k<m;k++)   
             {
                mat2[i][k]=0;

             }
              for(int k=0;k<n;k++)   
             {
                mat2[k][j]=0;
                
             }
            }
          }
     }

     
   matrix = mat2;
    }
};

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();        // number of rows
//         int m = matrix[0].size();     // number of columns

//         vector<bool> row(n, false);
//         vector<bool> col(m, false);

//         // First pass: mark rows and columns
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == 0) {
//                     row[i] = true;
//                     col[j] = true;
//                 }
//             }
//         }

//         // Second pass: set rows to 0
//         for (int i = 0; i < n; i++) {
//             if (row[i]) {
//                 for (int j = 0; j < m; j++) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }

//         // Third pass: set columns to 0
//         for (int j = 0; j < m; j++) {
//             if (col[j]) {
//                 for (int i = 0; i < n; i++) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }
// };
