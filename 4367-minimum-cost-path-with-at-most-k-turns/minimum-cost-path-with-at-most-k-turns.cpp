class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 1 && m == 1) return grid[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int ans = INT_MAX;
        pq.push({grid[0][0],0,0,4,0}); // dist, r, c, prevdir, turns
        vector<vector<vector<vector<int>>>> dist(n, vector<vector<vector<int>>>
                                            (m, vector<vector<int>>(5,vector<int>(k + 1, INT_MAX))));
        vector<int> x = {0,-1,0,1};
        vector<int> y = {1,0,-1,0};
        dist[0][0][4][0] = grid[0][0];

        while(!pq.empty()){
            int row = pq.top()[1];
            int col = pq.top()[2];
            int prevdir = pq.top()[3];
            int turns = pq.top()[4];
            int d = pq.top()[0];
            pq.pop();

            if(row == n-1 && col == m-1) return d;
            

            if(d > dist[row][col][prevdir][turns]) continue;

            for(int i = 0; i < 4; i++){
                int nr = row + x[i];
                int nc = col + y[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    // right = 0, down = 1, left = 2, up = 3
                    int nextturn;
                    if(prevdir == 4 || prevdir == i) nextturn = turns;
                    else nextturn = turns + 1;
                    
                    if(nextturn <= k && d+grid[nr][nc] < dist[nr][nc][i][nextturn] && d+grid[nr][nc] < ans){
                        dist[nr][nc][i][nextturn] = d + grid[nr][nc];
                        pq.push({d + grid[nr][nc], nr, nc, i, nextturn});
                    }
                }
            }
        }
        return -1;
    }
};