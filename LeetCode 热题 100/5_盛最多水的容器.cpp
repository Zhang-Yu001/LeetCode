class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, res = 0;
        while(left < right){
            res = max(res, min(height[left], height[right]) * (right - left));
            if(height[left] > height[right]) right--;
            else left++;
        }
        return res;
    }
};