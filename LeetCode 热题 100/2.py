class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<int> nums;
        for(int i = 0; i < len; i++){
            string str = strs[i];
            int num = 0;
            for(int j = 0; j < str.length(); j++){
                num += 1 << int(str[j] - 'a');
            }
            nums.push_back(num);
        }
        unordered_map<int, int> h;
        vector<vector<string>> results;
        for(int i = 0; i < len; i++){
            auto it = h.find(nums[i]);
            if(it == h.end()){
                vector<string> result;
                h[nums[i]] = i;
                result.push_back(strs[i]);
                for(int j = i + 1; j < len; j++){
                    if(nums[j] == nums[i]){
                        result.push_back(strs[j]);
                    }
                }
                results.push_back(result);
            }
        }
        return results;
    }
};