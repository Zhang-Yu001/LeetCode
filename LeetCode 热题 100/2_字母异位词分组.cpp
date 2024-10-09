class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results;
        unordered_map<string, vector<string>> hashtable;
        for(string& str : strs){
            string key = str;
            sort(key.begin(), key.end());
            hashtable[key].emplace_back(str);
        }
        for(auto it : hashtable){
            results.emplace_back(it.second);
        }
        return results;
     
        # vector<vector<string>> results;
        # vector<string> s;
        # unordered_map<string, vector<string>> hashtable;
        # unordered_map<string, int> hash;
        # for(int i = 0; i < strs.size(); i++){
        #     string str = strs[i];
        #     sort(str.begin(), str.end());
        #     s.push_back(str);
        #     auto it = hashtable.find(str);
        #     if(it != hashtable.end()){
        #         it->second.push_back(strs[i]);
        #     }
        #     else{
        #         vector<string> result;
        #         result.push_back(strs[i]);
        #         hashtable[str] = result;
        #     }
        # }
        # for(int i = 0; i < s.size(); i++){
        #     auto it = hash.find(s[i]);
        #     if(it == hash.end()){
        #         results.push_back(hashtable.find(s[i])->second);
        #         hash[s[i]] = i;
        #     }
        # }
        # return results;

            # int len = strs.size();
            # vector<int> nums;
            # for(int i = 0; i < len; i++){
            #     string str = strs[i];
            #     int num = 0;
            #     for(int j = 0; j < str.length(); j++){
            #         num += 1 << int(str[j] - 'a');
            #     }
            #     nums.push_back(num);
            # }
            # unordered_map<int, int> h;
            # vector<vector<string>> results;
            # for(int i = 0; i < len; i++){
            #     auto it = h.find(nums[i]);
            #     if(it == h.end()){
            #         vector<string> result;
            #         h[nums[i]] = i;
            #         result.push_back(strs[i]);
            #         for(int j = i + 1; j < len; j++){
            #             if(nums[j] == nums[i]){
            #                 result.push_back(strs[j]);
            #             }
            #         }
            #         results.push_back(result);
            #     }
            # }
            # return results;
    }
};