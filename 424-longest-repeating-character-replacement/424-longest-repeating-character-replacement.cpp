class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 1;
        char maxChar = s[0];
        vector<int> mp(256,0);
        
        int l=0;
        for(int r=0;r<s.length();r++){
            mp[s[r]]++;
            
            if(mp[s[r]]>=mp[maxChar]){
                maxChar = s[r];
            }
            
            // we don't need loop to update maxChar since maxcount in the window is count[maxChar].
            // when we move l to right, the maximum of counts remains less than the maxcount.
            while((r-l+1)-mp[maxChar] > k){
                mp[s[l]]--;
                l++;
            }
            
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};