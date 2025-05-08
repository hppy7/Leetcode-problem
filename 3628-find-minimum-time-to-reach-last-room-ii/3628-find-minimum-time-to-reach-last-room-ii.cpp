class Solution 
{
public:
vector<vector<int>> direction{{1,0},{-1,0},{0,1},{0,-1}};
typedef pair<int,pair<int,int>> p;
    int minTimeToReach(vector<vector<int>>& moveTime) {
  
     int m=moveTime.size();

     int n=moveTime[0].size();
     vector<vector<int>> result(m,vector<int>(n,INT_MAX));
      priority_queue<p,vector<p>,greater<p>> pq;
    result[0][0]=0;
    pq.push({0,{0,0}});
     while(!pq.empty())
     {
        int currTime=pq.top().first;
        auto cell=pq.top().second;
        int i=cell.first;
        int j=cell.second;
        pq.pop();
        if(i==m-1&& j==n-1){
            return currTime;
        }

        for(auto &dir : direction)
        {
            int i_=i+dir[0];
            int j_=j+ dir[1];
            if(i_>=0 && i_ < m && j_ >= 0 && j_<n )
            {
                int moveCost=(i+j)%2==0?1:2;
             int wait= max(moveTime[i_][j_]-currTime,0) ;
             int arrTime= currTime + wait +moveCost;
             if(result[i_][j_]> arrTime)  
             {
                result[i_][j_]= arrTime;
                pq.push({arrTime,{i_,j_}});
             }
            }
        
        }
     }
        return -1;
     }

};


