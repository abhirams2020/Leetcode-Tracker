class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int maxLen = 1;
        char maxChar = s[0];
        int l=0;
        for(int r=0;r<s.length();r++){
            count[s[r]]++;
            if(count[s[r]]>=count[maxChar]){
                maxChar = s[r];
            }
            while((r-l+1) - count[maxChar] > k){
                count[s[l]]--;
                if(count[s[r]] >= count[maxChar]){
                    maxChar = s[r];
                }
                if(count[s[l]] == 0){
                    count.erase(s[l]);
                }
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        
        return maxLen;
    }
};