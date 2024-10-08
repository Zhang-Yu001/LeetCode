class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = 0, res = 0;
        while(left < n - 1){
            int cnt = 0;
            while(!height[left]) left++;
            right = left + 1;
            while(right < n && height[right] < height[left]){
                cnt += height[right++];
            }
            if(right == n && height[right - 1] < height[left]){
                n = left - 1;
                left = height.size() - 1;
                right = height.size() - 1;
                while(left > n + 1){
                    cnt = 0;
                    while(!height[left]) left--;
                    right = left - 1;
                    while(right > n && height[right] < height[left]){
                        cnt += height[right--];
                    }
                    res += (left - right - 1) * height[left] - cnt;
                    left = right;
                }
                break;
            }
            else{
                res += (right - left - 1) * height[left] - cnt;
                left = right;
            }
        }
        return res;
    }
};