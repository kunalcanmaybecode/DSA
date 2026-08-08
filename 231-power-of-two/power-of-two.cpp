class Solution {
public:
    bool isPowerOfTwo(int n) {
        // int m = n;

        // if(m==1)
        //     return true;

        // for(int i = 0; i < 31; i++){
        //     if(m == pow(2,i))
        //         return true;
            
        //     else
        //         continue;
        // }
        // return false;

        return (n>0) && ((n & (n-1)) == 0);
        
    } 
};