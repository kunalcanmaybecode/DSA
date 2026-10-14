class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int high = 9;
        string ans;
        if(sum > num*9) return "";
        while(num > 0){
            if(sum > high){
                num--;
                sum -= high;
                ans+= to_string(high);
            }
            else{
                while(sum < high && high > 0){
                    high--;
                }
                num--;
                ans+= to_string(high);
                sum = 0;
                high = 0;
            }
        }
        
        return ans;
    }
};