class Solution {
public:
    bool checkString(string s) {                            
        bool bal = true;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'b') bal = false;
            if(s[i] == 'a' && bal == false){
                return false;
            }            
        }
        return true;
    }
};