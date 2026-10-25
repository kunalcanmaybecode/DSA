class DSU{
    vector<int> parent, Size;

public:
    DSU(int n){
        parent.resize(n + 1);
        Size.resize(n + 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            Size[i] = 1;
        }
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionBySize(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;
        if (Size[pu] >= Size[pv]) {
            Size[pu] += Size[pv];
            parent[pv] = pu;
        } 
        else {
            Size[pv] += Size[pu];
            parent[pu] = pv;
        }
        return true;        
    }
};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        DSU dsu(r*c+1);

        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 0){            
                    int indold = i * c + j;
                    if(i == 0 || i == r - 1 || j == 0 || j == c - 1){
                        dsu.unionBySize(indold, r*c);
                    }
                    for(auto k : dir){
                        int nr = k[0] + i;
                        int nc = k[1] + j;
                        if(nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc] == 0){
                            int indnew = nr * c + nc; 
                            dsu.unionBySize(indold, indnew);                           
                        }
                    }
                }
            }
        }
        
        unordered_set<int> ans;
        int border = dsu.find(r*c);

        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if(grid[i][j] == 0){
                    int root = dsu.find(i * c + j);
                    if(root != border) ans.insert(root);                    
                }
            }
        }

        return ans.size();
    }
};