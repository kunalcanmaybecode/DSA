class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex+1, vector<int> (rowIndex+1,1));
        for(int i = 1; i < rowIndex+1; i++){
            for(int j = 1; j < i; j++){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }

        return dp[rowIndex];
    }
};