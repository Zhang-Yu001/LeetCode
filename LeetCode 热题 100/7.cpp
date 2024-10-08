class Solution {
public:
    int trap(vector<int>& height) {
        // 动态规划
        int n = height.size() - 1;
        int leftmax[20010], rightmax[20010];
        int res = 0;
        leftmax[0] = height[0], rightmax[n] = height[n];
        for(int i = 1; i <= n; i++){
            leftmax[i] = max(leftmax[i - 1], height[i]);
        }
        for(int j = n - 1; j >= 0; j--){
            rightmax[j] = max(rightmax[j + 1], height[j]);
        }
        for(int i = 0; i <= n; i++){
            res += min(leftmax[i], rightmax[i]) - height[i];
        }
        return res;

        // int n = height.size();
        // int left = 0, right = 0, res = 0;
        // while(left < n - 1){
        //     int cnt = 0;
        //     while(!height[left]) left++;
        //     right = left + 1;
        //     while(right < n && height[right] < height[left]){
        //         cnt += height[right++];
        //     }
        //     if(right == n && height[right - 1] < height[left]){
        //         n = left - 1;
        //         left = height.size() - 1;
        //         right = height.size() - 1;
        //         while(left > n + 1){
        //             cnt = 0;
        //             while(!height[left]) left--;
        //             right = left - 1;
        //             while(right > n && height[right] < height[left]){
        //                 cnt += height[right--];
        //             }
        //             res += (left - right - 1) * height[left] - cnt;
        //             left = right;
        //         }
        //         break;
        //     }
        //     else{
        //         res += (right - left - 1) * height[left] - cnt;
        //         left = right;
        //     }
        // }
        // return res;
    }
};