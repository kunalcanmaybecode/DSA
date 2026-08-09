class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int area = 0, maxi = 0;
        while(left < right){
            if(height[left] > height[right]){
                area = height[right] * (right - left);
                right--;
            }
            else{
                area = height[left] * (right - left);
                left++;
            }
            maxi = max(maxi, area);
        }
        return maxi;
    }
};