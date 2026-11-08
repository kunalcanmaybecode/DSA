class DSU{
public:
    vector<int> parent;
    vector<int> Size;
    DSU(int n){
        parent.resize(n);
        Size.resize(n);

        for(int i = 0; i < n; i++){
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

    void Union(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        if(Size[px] > Size[py]){
            Size[px] += Size[py];
            parent[py] = px;
        }
        else if(Size[px] < Size[py]){
            Size[py] += Size[px];
            parent[px] = py;            
        }
        else{
            Size[px] += Size[py];
            parent[py] = px;
        }

    }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DSU dsu(n*m);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int cur = i * m + j;
                if(grid[i][j] == 1){
                    for(int k = 0; k < n; k++){                        
                        if(k != i && grid[k][j] == 1){
                            dsu.Union(cur, k*m + j);
                            break;
                        }                        
                    }
                    for(int k = 0; k < m; k++){                        
                        if(k != j && grid[i][k] == 1){
                            dsu.Union(cur, i*m + k);
                            break;
                        }                        
                    }
                }
            }
        }

        int ans = 0;
        unordered_set<int> mp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int idx = i * m + j;
                    int p = dsu.find(idx);
                    if(dsu.Size[p] > 1){
                        if(mp.find(p) == mp.end()){
                            mp.insert(p);
                            ans += dsu.Size[p];
                        }
                    }
                }
            }
        }
        return ans;
    }
};