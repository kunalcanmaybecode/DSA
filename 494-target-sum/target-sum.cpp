class Solution {
private:
    int countSubsets(vector<int>& nums, int ind, int target, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target == 0 && nums[0] == 0) return 2;
            if (target == 0 || target == nums[0]) return 1; 
            return 0;
        }

        if (dp[ind][target] != -1) return dp[ind][target];

        int notPick = countSubsets(nums, ind - 1, target, dp);
        int pick = 0;
        if (nums[ind] <= target) pick = countSubsets(nums, ind - 1, target - nums[ind], dp);
        return dp[ind][target] = pick + notPick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if ((totalSum - target) < 0 || (totalSum - target) % 2 != 0)  return 0;

        int subsetSum = (totalSum - target) / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(subsetSum + 1, -1));
        return countSubsets(nums, nums.size() - 1, subsetSum, dp);
    }
};