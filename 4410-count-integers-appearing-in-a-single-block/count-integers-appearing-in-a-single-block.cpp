class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_set<int> visited;    
        unordered_set<int> invalid;    
        unordered_set<int> allUnique;  

        for(int i = 0; i < nums.size(); i++) {
            allUnique.insert(nums[i]);
            
            if(visited.count(nums[i])) {
                invalid.insert(nums[i]);
            }

            if(i + 1 == nums.size() || nums[i] != nums[i + 1]) {
                visited.insert(nums[i]);
            }
        }

        return allUnique.size() - invalid.size();
    }
};