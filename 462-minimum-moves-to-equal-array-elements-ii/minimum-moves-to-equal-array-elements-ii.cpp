class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int median = 0;
        if(n == 1) return 0;
        sort(nums.begin(), nums.end());
        if(n%2 == 0){
            median = (n-1)/2;
        }
        else{
            median = n/2;
        }
        int moves = 0;
        for(int i : nums){
            moves += abs(i-nums[median]);
        }
        return moves;
    }
};