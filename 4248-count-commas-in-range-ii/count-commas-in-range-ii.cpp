class Solution {
public:
    long long countCommas(long long n) {
        int comma = 0;
        long long x = n;
        if(n < 1000) return 0;
        else{
            while(x >= 1000){
                comma++;
                x = x/1000;
            }
        }
        long long curr = 1000;
        long long next = 1000000;
        long long sum = 0;
        for(int i = 1; i <= comma; i++){
            if(i == comma){
                sum += (n - curr + 1) * i;
            }
            else{
                sum += (next - curr) * i; 
                curr *= 1000;
                next *= 1000;
            }
        }
        return sum;
    }
};