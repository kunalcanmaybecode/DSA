class Solution {
public:
    int solve(vector<int>& cuts, int start, int end, vector<vector<int>> &dp){
        if(start+1>=end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int finalcost=1e9;
        for(int i=start+1; i<end; i++){
            int cost=(cuts[end]-cuts[start])+solve(cuts, start, i, dp)+solve(cuts, i, end, dp);
            finalcost=min(finalcost, cost);
        }
        return dp[start][end]=finalcost;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int> (cuts.size(), -1)); //dp stores min cost
        return solve(cuts, 0, cuts.size()-1, dp);
    }
};