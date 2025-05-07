class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();  // Number of rows
        int m = moveTime[0].size();  // Number of columns
        
        // Min-heap (priority queue) to simulate Dijkstra's algorithm
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        // Starting point (0, 0) at time 0
        pq.push({0, {0, 0}});
        
        // A matrix to store the minimum time to reach each cell
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        time[0][0] = 0;

        // Direction vectors for moving in 4 directions (up, left, down, right)
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        
        while (!pq.empty()) {
            int t = pq.top().first;  // Current time to reach (r, c)
            int r = pq.top().second.first;  // Current row
            int c = pq.top().second.second;  // Current column
            pq.pop();
            
            // Explore the 4 adjacent cells
            for (int i = 0; i < 4; i++) {
                int delrow = r + drow[i];
                int delcol = c + dcol[i];
                
                // Check if the new cell is within bounds
                if (delrow >= 0 && delrow < n && delcol >= 0 && delcol < m) {
                    int mTime = moveTime[delrow][delcol];  // Move time to reach the adjacent room
                    int newTime = max(mTime + 1, t + 1);  // New time after moving to this room
                    
                    // If the new time is less than the current known time for the adjacent room, update it
                    if (newTime < time[delrow][delcol]) {
                        time[delrow][delcol] = newTime;
                        pq.push({newTime, {delrow, delcol}});  // Push the new time and coordinates into the priority queue
                    }
                }
            }
        }
        
        // The minimum time to reach the bottom-right corner (n-1, m-1)
        return time[n - 1][m - 1];
    }
};
