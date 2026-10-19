class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int counttarget = 0;
        int ind = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < target) ind++;
            else if(nums[i] == target) counttarget++;
        }
        vector<int> ans;
        for(int i = 0; i < counttarget; i++){
            ans.push_back(ind + i);
        }
        return ans;
    }
};