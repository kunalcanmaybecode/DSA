class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 1;
        int end = nums.size() - 2;

        if(nums.size() == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[nums.size() - 1] != nums[nums.size() - 2]) return nums[nums.size() - 1];
        
        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

            if(nums[mid] == nums[mid+1]){
                if(mid%2 == 0) start = mid + 1;
                else end = mid -1;
            }
            if(nums[mid] == nums[mid-1]){
                if(mid%2 == 0) end = mid - 1;
                else start = mid + 1;
            }
        }
        return nums[start];
    }
};