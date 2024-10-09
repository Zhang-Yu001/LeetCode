class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.length(), res = 0;
        int left = 0, right = 0;
        while(right < n){
            if (mp.find(s[right]) != mp.end()) {
                left = max(left, mp[s[right]] + 1);
            }
            mp[s[right]] = right;
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};