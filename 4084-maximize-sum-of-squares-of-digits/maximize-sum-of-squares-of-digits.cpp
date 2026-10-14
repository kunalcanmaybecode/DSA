class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        unordered_map<int,int> mp;
        int high = 9;
        if(sum > num*9) return "";
        while(num > 0){
            if(sum > high){
                num--;
                mp[high]++;
                sum -= high;
            }
            else{
                while(sum < high && high > 0){
                    high--;
                }
                num--;
                mp[high]++;
                sum = 0;
                high = 0;
            }
        }
        
        string ans = "";
        
        for(auto i : mp){
            int count = i.second;
            while(count--){
                ans += to_string(i.first);
            }
        }

        sort(ans.rbegin(), ans.rend());
        return ans;
    }
};