class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxi = 0;
        for(char c: s){
            if(c == '('){ 
                depth++;
                maxi = max(depth,maxi);
            }
            else if(c == ')') depth--;
        }
        return maxi;
    }
};