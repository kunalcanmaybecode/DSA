class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int l = 0;
        int sum = 0;
        int n = nums.size();
        if(nums.size() <3) return 0;
        for(int i = 1; i < n-1; i++){
            int currdiff = nums[i] - nums[l];
            int lenght = 2;
            while(i < n-1 && currdiff == nums[i+1] - nums[i]){
                lenght++;
                i++;
                sum += (lenght - 3 + 1);
            }
            l = i;
        }
        return sum;
    }
};