class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        unordered_map<int,int> mp;
        vector<int> ans(n);
        
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() <= temperatures[i]){
                st.pop();
            }

            if(st.empty()) ans[i] = 0;
            else{
                ans[i] = mp[st.top()] - i;
            }
            st.push(temperatures[i]);
            mp[temperatures[i]] = i;
        }
        return ans;
    }
};