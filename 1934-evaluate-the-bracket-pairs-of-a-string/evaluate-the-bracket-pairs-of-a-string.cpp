class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int ind = 0;
        int n = s.size();
        string ans;
        unordered_map<string,string> mp;

        for(int i = 0; i < knowledge.size(); i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        while(ind < n){
            if(s[ind] == '('){
                string curr;
                ind++;
                while(s[ind] != ')'){
                    curr += s[ind];
                    ind++;
                }
                ind++;
                if(mp.count(curr)) ans += mp[curr];
                else ans += '?';
            }
            else{
                ans += s[ind];
                ind++;
            }
        }
        return ans;
    }
};