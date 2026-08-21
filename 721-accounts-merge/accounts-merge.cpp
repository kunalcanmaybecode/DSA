class DSU{
    public:
    vector<int> rank, parent, size;
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node) {
        if (node == parent[node]) return node;
        return parent[node] = find(parent[node]);;
    }

    void unionBySize(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);

        unordered_map<string, int> mpp;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mpp.find(mail) == mpp.end()) mpp[mail] = i;
                else dsu.unionBySize(i, mpp[mail]);             
            }
        }

        vector<vector<string>> merged(n);

        for(auto it : mpp){
            string mail = it.first;
            int node = dsu.find(it.second);
            merged[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (merged[i].empty()) continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (auto &mail : merged[i]) {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};