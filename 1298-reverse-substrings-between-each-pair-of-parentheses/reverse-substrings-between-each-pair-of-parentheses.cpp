class Solution {

public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> brackets(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                int j = st.top();
                st.pop();
                brackets[i] = j;
                brackets[j] = i;
            }
        }

        string res;
        int i = 0;
        int dir = 1;

        while(i >=0 and i < n){
            if(s[i] == '(' || s[i] == ')'){
                i = brackets[i];
                dir = -dir;
            }
            else res += s[i];
            i += dir;
        }
        return res;
    }
};