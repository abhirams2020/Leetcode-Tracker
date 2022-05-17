class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int maxLen = 1;
        char maxChar = s[0];
        int l=0;
        for(int r=0;r<s.length();r++){
            count[s[r] - 'A']++;
            if(count[s[r] - 'A']>=count[maxChar - 'A']){
                maxChar = s[r];
            }
            while((r-l+1) - count[maxChar - 'A'] > k){
                count[s[l] - 'A']--;
                
                // we don't need loop to update maxChar since maxcount in the window is count[maxChar].
                // when we move l to right, the maximum of counts remains less than the maxcount.
                
                // if(count[s[r]] >= count[maxChar]){
                //     maxChar = s[r];
                // }
                
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};