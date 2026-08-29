class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n,0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else if(rank[py] > rank[px]){
            parent[px] = py;
        }
        else{
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        DSU dsu(n);

        vector<vector<int>> ind;
        for (int i = 0; i < n; i++) {
            ind.push_back({nums[i], i});
        }

        sort(ind.begin(), ind.end());

        for (int i = 1; i < n; i++) {
            if (ind[i][0] - ind[i - 1][0] <= limit) {
                dsu.unite(ind[i][1], ind[i - 1][1]);
            }
        }

        unordered_map<int, vector<int>> index;
        unordered_map<int, vector<int>> val;

        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            index[root].push_back(i);
            val[root].push_back(nums[i]);
        }

        vector<int> result(n);
        for (auto i : index) {
            int comp = i.first;
            vector<int> indices = i.second;
            vector<int> values = val[comp];

            sort(indices.begin(), indices.end());
            sort(values.begin(), values.end());

            for (int k = 0; k < indices.size(); k++) {
                result[indices[k]] = values[k];
            }
        }

        return result;
    }
};