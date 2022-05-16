class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxVal = 0;
        unordered_map<char,int> mp;
        int l=0,r=0;
        while(r < s.length()){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
            maxVal = max(maxVal, r-l+1);
            r++;
        }
        return maxVal;
    }
};