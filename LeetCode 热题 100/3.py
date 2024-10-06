class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int result = 0;
        for(int num : nums){
            auto it = mp.find(num);
            if(it == mp.end()){
                auto it_2 = mp.find(num - 1);
                if(it_2 == mp.end()) mp[num] = 1;
                else mp[num] = it_2->second + 1;
            }
            result = max(result, mp[num]);
        }
        return result;
    }
};