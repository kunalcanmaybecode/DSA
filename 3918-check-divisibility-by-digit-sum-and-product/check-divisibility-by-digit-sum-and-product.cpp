class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int x = n, y = n;
        while(y > 0){
            int rem = y%10;
            sum = sum+rem;
            y = y/10;
        }

        while(x>0){
            int rem = x%10;
            if(rem == 0){
                prod = 0;
                break;
            }
            prod *= rem;
            x = x/10;
        }

        return n%(sum+prod) == 0? true:false; 

    }
};