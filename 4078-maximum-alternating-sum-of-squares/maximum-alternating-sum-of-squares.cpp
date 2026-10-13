class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = abs(nums[i]);
        }
        if(nums.size() == 1){
            return nums[0]*nums[0];
        }
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int s = 0;
        int e = nums.size() - 1;

        while(s < e){
            if(s+2 == e){
                long long pos = (nums[e]*nums[e]);
                long long neg = -1 * (nums[s]*nums[s]);
                ans += pos + neg;
                e--;
                ans += (nums[e]*nums[e]);
                break;
            }
            else{
                long long pos = (nums[e]*nums[e]);
                long long neg = -1 * (nums[s]*nums[s]);
                ans += pos + neg;
                e--;
                s++;
            }
        }
        return ans;
    }
};