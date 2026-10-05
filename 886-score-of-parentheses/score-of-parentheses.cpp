class Solution {
public:
    // ((()()()))
    // ((()))
    int scoreOfParentheses(string s) {
        int depth = 1;
        int n = s.size();
        int ans = 0;
        char prev = '(';
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                depth = depth << 1;
            }
            else{
                depth = depth >> 1;
                if(prev == '(') ans += depth;
            }
            prev = s[i];
        }
        return ans;
    }
};