class Solution {
private:
    int solve(int n){
        int sum = 0;
        while(n > 0){
            int rem = n%10;
            sum += rem;
            n = n/10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int ind = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            if(solve(nums[i]) == i) ind = min(ind, i);
        }
        return ind== INT_MAX? -1: ind;
    }
};