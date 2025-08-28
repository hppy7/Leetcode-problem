class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n;
        n=grid.size();
        int p,t;
        for(int k=0;k<n;k++)
        {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>=j){
                    p=i;
                    t=j;
                if(p+1 <n && t+1 <n  && grid[i][j]<grid[p+1][t+1])
                {
                    int tem =grid[p+1][t+1];
                    grid[p+1][t+1]=grid[p][t];
                    grid[p][t]=tem;
                }
                }else if(j>i){
                    p=i;
                    t=j;
                if( t+1<n && p+1 <n  && grid[i][j]>grid[p+1][t+1] )              {
                    int tem =grid[i][j];
                    grid[i][j]=grid[p+1][t+1];
                    grid[p+1][t+1]=tem;
                }
                }

            }
        }
        }
        return grid;
    }

};