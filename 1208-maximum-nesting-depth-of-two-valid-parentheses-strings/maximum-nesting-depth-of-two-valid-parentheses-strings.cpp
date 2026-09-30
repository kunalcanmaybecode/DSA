class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int bal = 0;
        int n = seq.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            if(seq[i] == '('){
                bal++;
                ans[i] = bal % 2; 
            }
            else if(seq[i] == ')'){
                ans[i] = bal % 2;
                bal--;
            }
        }
        return ans;
    }
};