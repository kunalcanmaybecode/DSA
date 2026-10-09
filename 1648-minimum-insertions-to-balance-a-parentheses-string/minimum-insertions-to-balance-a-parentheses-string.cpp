class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int bal = 0;

        for (char c : s) {
            if(c == '(') {
                if(bal % 2 != 0) {
                    ans++;           
                    bal--; 
                }
                bal += 2;  
            } 
            else{
                bal--;
                if(bal < 0) {
                    ans++;           
                    bal += 2; 
                }
            }
        }

        return ans + bal;
    }
};