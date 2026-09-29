class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        int max_open = (m + n - 1) / 2;
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(max_open + 1, false)));

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        vis[0][0][1] = true;

        int dirx[] = {0, 1};
        int diry[] = {1, 0};

        while (!q.empty()) {
            auto [pos, curr] = q.front();
            int x = pos.first;
            int y = pos.second;
            q.pop();
            if (x == m - 1 && y == n - 1 && curr == 0) return true;
            
            for (int i = 0; i < 2; i++) {
                int nx = x + dirx[i];
                int ny = y + diry[i];

                if (nx < m && ny < n) {
                    int curr_bal = curr + (grid[nx][ny] == '(' ? 1 : -1);
                    if (curr_bal >= 0 && curr_bal <= max_open && !vis[nx][ny][curr_bal]) {
                        vis[nx][ny][curr_bal] = true;
                        q.push({{nx, ny}, curr_bal});
                    }
                }
            }
        }
        return false;
    }
};