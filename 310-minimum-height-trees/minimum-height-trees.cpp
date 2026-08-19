class Solution {

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 2) {
            vector<int> res;
            for (int i = 0; i < n; ++i) res.push_back(i);
            return res;
        }

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        queue<pair<int,int>> q;

        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 1) q.push({i,0});
        }

        int maxi = 0;
        vector<int> nodes(n);
        while(!q.empty()){
            int node = q.front().first;
            int depth = q.front().second;
            q.pop();
            nodes[node] = depth;
            maxi = max(maxi,depth);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 1) q.push({it,depth+1});
            }
        }

        vector<int>res;
        for(int i = 0; i < n; i++){
            if(nodes[i] == maxi) res.push_back(i);
        }
        return res;
    }
};