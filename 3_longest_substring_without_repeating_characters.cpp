class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int charac[256] = {0};
        int ans = 0;
        while(right < s.size()){
            charac[s[right]]++;
            while(charac[s[right]] > 1){
                charac[s[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};