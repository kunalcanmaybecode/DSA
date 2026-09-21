class Solution {
private:
    bool isPalindrome(string& s, int left, int right) {        
        while (left < right) {
            if (s[left] != s[right]) return false;            
            left++;
            right--;
        }
        return true;
    }

    int solve(string& s, int end, vector<int>& dp) {
        if (end == 0) return 0;
        if (dp[end] != -1) return dp[end];
        
        int best = s.size() + 1;
        for (int start = end - 1; start >= 0; start--) {
            if (isPalindrome(s, start, end - 1)) {
                int current = 1 + solve(s, start, dp);
                best = min(best, current);
            }
        }
        dp[end] = best;
        return dp[end];
    }
public:
    int minCut(string s) {
        if(s.size() == 0) return 0;
        
        vector<int> dp(s.size() + 1, -1);
        int pieces = solve(s, s.size(), dp);
        return pieces - 1;
    }
};