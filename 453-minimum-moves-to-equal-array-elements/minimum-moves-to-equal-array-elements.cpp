class Solution {
public:
    int minMoves(vector<int>& nums) {
    // 1 2 3 4    1 1 2 3   3 4 4 6    2 2 3 3 5 5 6
    // 2 3 4 4    2 2 3 3   4 5 5 6    3 3 4 4 6 6 6
    // 3 4 5 4    3 3 4 3   5 6 6 6    4 4 5 5 7 7 6
    // 4 5 5 5    4 4 4 4   6 7 7 6    5 5 6 6 8 7 7 
    // 5 6 6 5              7 8 7 7    6 6 7 7 8 8 8
    // 6 6 7 6              8 8 8 8    7 7 8 8 9 9 8
    // 7 7 7 7                         8 8 9 9 10 9 9
    //                                 9 9 10 10 10 10 10
    //                                 10 10 11 11 11 11 10
    //                                 11 11 12 12 12 11 11
    //                                 12 12 13 13 12 12 12
    //                                 13 13 14 13 13 13 13
    //                                 14 14 14 14 14 14 14
        int mini = INT_MAX;
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++){
            mini = min(mini, nums[i]);            
        }

        for(int i = 0; i < nums.size(); i++){
            cnt += nums[i] - mini;
        }
        return cnt;

    }
};