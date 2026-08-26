class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;

        for(int i = 0; i < asteroids.size(); i++){
            if(st.empty()) st.push(asteroids[i]);
            else if(asteroids[i] + st.top() == 0 && st.top() > 0) st.pop();
            else if(st.top() < 0 || asteroids[i] > 0) st.push(asteroids[i]);
            else{
                while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) st.pop();
                if(st.empty() || st.top() < 0) st.push(asteroids[i]);
                else if(st.top() + asteroids[i] == 0) st.pop();
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
