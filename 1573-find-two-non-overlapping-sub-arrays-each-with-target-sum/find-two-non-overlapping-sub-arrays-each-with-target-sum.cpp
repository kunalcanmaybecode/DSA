class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> len(n, INT_MAX);
        unordered_map<int, int> mp;
        mp[0] = -1;

        int prefix = 0;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            prefix += arr[i];

            if (mp.count(prefix - target)){
                int left = mp[prefix - target];
                int curr = i - left;

                if (left >= 0 && len[left] != INT_MAX) ans = min(ans, curr + len[left]);
                
                if (i > 0) len[i] = min(len[i - 1], curr);                
                else len[i] = curr;
                
            } 
            else{
                if(i > 0) len[i] = len[i - 1];               
            }
            mp[prefix] = i;
        }
        return ans >= INT_MAX ? -1 : ans;
    }
};