class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string s;
        if(m == 1 || n == 1){
            for(int i = 0; i < n; i++){
                s.push_back('.');
            }
            for(int i = 0; i < m; i++){
                ans.push_back(s);
            }
        }
        else{
            for(int i = 0; i < n; i++){
                s.push_back('.');
            }
            string x;
            for(int i = 0; i < n-1; i++){
                x.push_back('#');
            }
            x.push_back('.');
            ans.push_back(s);
            for(int i = 0; i < m-1; i++){
                ans.push_back(x);
            }
        }
        return ans;
    }
};