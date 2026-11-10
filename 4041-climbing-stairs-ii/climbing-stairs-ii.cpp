class Solution {
private:
    int solve(int ind, vector<int>& costs, vector<int>& dp){
        if(ind <= -1){
            return 0;
            dp[ind] = 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int take3 = 9 + solve(ind-3, costs, dp);
        int take2 = 4 + solve(ind-2, costs, dp);
        int take1 = 1 + solve(ind-1, costs, dp);       
        return dp[ind] = costs[ind] + min(take1, min(take2, take3));
    }
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        int ans = solve(n-1,costs, dp);
        return ans;
    }
};