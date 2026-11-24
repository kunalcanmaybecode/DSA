class Solution {
private:
    int gcd(int num1, int num2){
        int maxi = 1;
        for(int i = 1; i <= min(num1, num2); i++){
            if(num1 % i == 0 && num2 % i == 0){
                maxi = max(i, maxi);
            }
        }
        return maxi;
    }
    int lcm(int num1, int num2){
        if (num1 == 0 || num2 == 0) return 0;        
        return (num1 / gcd(num1, num2)) * num2; 
    }
public:
    int maxLength(vector<int>& nums) {
        int maxlen = 0;
        for(int i = 0; i < nums.size(); i++){        
            int currentgcd = nums[i];
            int currentlcm = nums[i];
            long long prod = 1;

            for(int j = i; j < nums.size(); j++){
                prod *= nums[j];
                if(prod > 25200) break; 

                currentgcd = gcd(currentgcd, nums[j]);
                currentlcm = lcm(currentlcm, nums[j]);
                
                if(prod == (long long)currentgcd * currentlcm){
                    maxlen = max(maxlen, j - i + 1);
                }
            }                                   
        }
        return maxlen;
    }
};