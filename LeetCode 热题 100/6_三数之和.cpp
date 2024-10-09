class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i] > 0) break;
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i], right = nums.size() - 1;
            for(int left = i + 1; left < nums.size() - 1; left++){
                if(left != i + 1 && nums[left] == nums[left - 1]) continue;
                while(left < right && nums[left] + nums[right] > target) right--;
                if(left == right) break;
                if(nums[left] + nums[right] == target) res.push_back({nums[i], nums[left], nums[right]});
            }
        } 
        return res;
    }
};