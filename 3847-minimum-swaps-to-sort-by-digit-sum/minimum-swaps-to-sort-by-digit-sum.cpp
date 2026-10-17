class Solution {
private:
    int solve(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> digit_sum(n);

        for (int i = 0; i < n; i++) {
            digit_sum[i] = solve(nums[i]);
        }

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int i, int j) {
            if (digit_sum[i] != digit_sum[j]) return digit_sum[i] < digit_sum[j];
            return nums[i] < nums[j];
        });

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || idx[i] == i) continue;
            
            int cycle_size = 0;
            int curr = i;

            while (!visited[curr]) {
                visited[curr] = true;
                curr = idx[curr];
                cycle_size++;
            }

            if (cycle_size > 1) swaps += (cycle_size - 1);
            
        }

        return swaps;


    }
};