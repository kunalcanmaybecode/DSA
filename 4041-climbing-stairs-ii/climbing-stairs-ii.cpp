class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n <= 0) return 0;
        
        vector<int> dp(n, 0);
        
        for(int i = 0; i < n; ++i) {
            int take1 = 1 + (i - 1 >= 0 ? dp[i - 1] : 0);
            int take2 = 4 + (i - 2 >= 0 ? dp[i - 2] : 0);
            int take3 = 9 + (i - 3 >= 0 ? dp[i - 3] : 0);            
            dp[i] = costs[i] + min(take1, min(take2, take3));
        }
        
        return dp[n - 1];
    }
};