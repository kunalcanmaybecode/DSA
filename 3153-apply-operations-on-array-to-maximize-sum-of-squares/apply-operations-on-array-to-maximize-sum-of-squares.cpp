class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int MOD = 1e9 + 7;
        vector<int> count(31, 0);

        for(int x : nums){
            for(int b = 0; b < 31; b++){
                if((x >> b) & 1) count[b]++;                
            }
        }

        long long sum = 0;
        for (int i = 0; i < k; i++) {
            long long val = 0;
            for (int b = 0; b < 31; b++) {
                if (count[b] > 0) {
                    val |= (1LL << b);
                    count[b]--;
                }
            }
            sum = (sum + (val % MOD) * (val % MOD)) % MOD;
        }

        return sum;
    }
};