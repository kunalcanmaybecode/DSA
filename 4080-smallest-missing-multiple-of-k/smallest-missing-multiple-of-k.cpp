class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int start = k;
        int end = k*(nums.size()+1);
        unordered_set<int> hs;
        for(int i: nums){
            hs.insert(i);
        }
        for(int i = 1; i < nums.size()+1; i++){            
            int multiple = k * i;
            if(hs.count(multiple) == 0) return multiple;
                        
        }
        return end;
    }
};