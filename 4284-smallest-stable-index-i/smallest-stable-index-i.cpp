class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi;
        vector<int> mini(n);

        for(int i = 0; i < nums.size(); i++){
            if(maxi.empty()){
                maxi.push_back(nums[i]);
                continue;
            }
            if(maxi.back() < nums[i]) maxi.push_back(nums[i]);
            else maxi.push_back(maxi.back());
        }
        int low = INT_MAX;
        for(int i = n - 1; i >= 0; i--){
            if(mini.empty()){
                mini[i] = nums[i];
                low = min(low, nums[i]);
                continue;
            }
            if(low > nums[i]){
                mini[i] = nums[i];
                low = nums[i];
            }
            else mini[i] = low;
        }

        int ans = INT_MAX;
        int ind = INT_MAX;
        for(int i = 0; i < n; i++){
            int diff = maxi[i] - mini[i];
            if(diff <= k){
                ind = min(ind, i);
            }
        }
        return ind == INT_MAX?-1:ind;
    }
};