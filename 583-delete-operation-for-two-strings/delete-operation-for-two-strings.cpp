class Solution {
public:
    int minDistance(string word1, string word2) {
        // int n = s1.length();
        // int m = s2.length();

        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
        //         else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        //     }
        // }

        // int lcs = dp[n][m];
        // return (n - lcs) + (m - lcs);

        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int j = 0; j <= n; ++j) dp[0][j] = j;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);                 
            }
        }

        return dp[m][n];
    }
};