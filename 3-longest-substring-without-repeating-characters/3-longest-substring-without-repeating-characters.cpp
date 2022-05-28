class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        vector<int> mp(256,0);
        int l = 0;
        for(int r=0;r<s.length();r++){
            while(mp[s[r]]>0){
                mp[s[l]]--;
                l++;
            }
            mp[s[r]]++;
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};