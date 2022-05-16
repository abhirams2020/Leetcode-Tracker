class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxVal = 0;
        vector<int> mp(256,0);
        int l=0,r=0;
        while(r < s.length()){
            while(mp[s[r]]>0){
                mp[s[l]]--;
                l++;
            }
            mp[s[r]]++;
            maxVal = max(maxVal, r-l+1);
            r++;
        }
        return maxVal;
    }
};