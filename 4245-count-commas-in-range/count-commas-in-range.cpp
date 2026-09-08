class Solution {
public:
    int countCommas(int n) {
        if(n < 1000) return 0;
        else{
            int div = n/1000;
            int rem = n%1000;
            return (div-1) * 1000 + rem + 1;
        }
    }
};