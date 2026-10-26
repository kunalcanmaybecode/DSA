class DSU {
    vector<int> parent, Size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        Size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            Size[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return false;
        if(Size[pu] >= Size[pv]){
            Size[pu] += Size[pv];
            parent[pv] = pu;
        } 
        else{
            Size[pv] += Size[pu];
            parent[pu] = pv;
        }
        return true;
    }
};

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        DSU dsu(m * n);

        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0){
                    int indold = i * n + j;

                    for(auto d : dir) {
                        int nr = i + d[0];
                        int nc = j + d[1];

                        if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0){
                            int indnew = nr * n + nc;
                            dsu.unionBySize(indold, indnew);
                        }
                    }
                }
            }
        }

        unordered_map<int, long long> sum;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    int root = dsu.find(i * n + j);
                    sum[root] += grid[i][j];
                }
            }
        }

        int ans = 0;
        for (auto i : sum){
            if(i.second % k == 0) ans++;
        }
        return ans;
    }
};