class Solution {
private:
    void dfs(vector<int> &visited, vector<vector<int>> &adj, int node){
        visited[node] = 1;

        for(int i: adj[node]){
            if(!visited[i]){
                dfs(visited, adj, i);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        vector<vector<int>> adj(n);
        vector<int> visited(n,0);
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                dfs(visited, adj, i);
            }
        }
        return count -1;
    }
};