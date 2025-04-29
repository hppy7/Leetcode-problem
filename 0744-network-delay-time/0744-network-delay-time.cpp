class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> adj(n+1);
    vector<bool> visited(n+1,false);
    for(auto &edge : times)
    {
   int u=edge[0],v=edge[1],w=edge[2];
   adj[u].push_back({v,w});

    }
    vector<int> dist(n+1,INT_MAX);
    dist[k]=0;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
      pq.push({0,k});
      while(!pq.empty())
      {
          int curtime=pq.top().first;
          int curnode=pq.top().second;
          pq.pop();
         if(visited[curnode])
         continue;

         visited[curnode]=true;
          for(auto& val:adj[curnode])
          {
            int newtime=curtime+val.second;
            if(newtime<dist[val.first])
            dist[val.first]=newtime;
            pq.push({newtime,val.first});
          }

      }
int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==INT_MAX)
        return -1;
        ans=max(ans,dist[i]);
    }
    return ans;
    }
};