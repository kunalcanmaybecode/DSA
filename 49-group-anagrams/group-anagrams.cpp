class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for (string s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            mpp[sorted].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto i : mpp) {
            ans.push_back(i.second);
        }

        return ans;
    }
};