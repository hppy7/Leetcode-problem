class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();
        int sum=0,sum1=0;
        int sum2=n*(n+1)/2;
        bool ans;
        for(int i=0;i<n;i++)
        {    sum=0;
          set<int> s;
            for(int j=0;j<m;j++)
            {
        s.insert(matrix[i][j]);
                // if(matrix[i][j]>sum1 || matrix[i][j]<sum1)
                //    sum+=matrix[i][j];

                 


            }
            if (s.size() != n) return false;
     
        for (int x : s) {
                 sum+=x;
                }
               if(sum==sum2)
                   {
                    ans=true;
                   }else
                   {
                    return false;
                   }
        }

         for(int i=0;i<n;i++)
        {
            sum1=0;
            set<int> s;
            for(int j=0;j<m;j++)
            {
                s.insert(matrix[j][i]);
                
            


            }
            if (s.size() != n) return false;
            for (int x : s) {
                 sum1+=x;
                }
        
           if(sum1==sum2)
                   {
                    ans=true;
                   }else
                   {
                   return false;
                   }

        }

        return ans;
        
    }

};