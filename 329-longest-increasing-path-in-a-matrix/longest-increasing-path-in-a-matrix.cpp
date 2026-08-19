class Solution {
private:
    int dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp, int m, int n){
        if(dp[row][col] != 0) return dp[row][col];

        vector<int> nrow = {0,0,-1,1};
        vector<int> ncol = {1,-1,0,0};
        int maxi = 1;
        for(int i = 0; i < 4; i++){
            int nr = nrow[i] + row;
            int nc = ncol[i] + col;

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[row][col]){
                maxi = max(maxi, 1 + dfs(nr, nc, matrix, dp, m , n));
            }
        }
        return dp[row][col] = maxi;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int maxi = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxi = max(maxi, dfs(i, j, matrix, dp, m, n));
            }
        }

        return maxi;
    }
};