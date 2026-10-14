class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > num*9) return "";
        int x = sum/9;
        int r = sum%9;
        string ans;
        for(int i = 0; i < x; i++){
            ans += to_string(9);
        }
        if(r != 0){
            ans += to_string(r);
        }
        if(ans.size() < num){
            while(num - ans.size() > 0){
                ans+='0';
            }
        }
        return ans;
    }
};