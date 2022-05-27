class Solution {
public:
    
    // FIND LARGEST POSSIBLE LENGTH BY EXPANDING FROM L AND R
    // IF s[l]!=s[r] STOP THE LOOP AND RETURN LENGTH
    int solve(string &s, int l, int r){
        int maxLen = 1;
        while(l>=0 && r<s.length() && s[l]==s[r]){
            maxLen = r-l+1;
            l--;
            r++;
        }
        return maxLen;
    }
    
    string longestPalindrome(string &s) {
        int maxLen = 0;
        int maxLeft = 0;
        
        // WE CONSIDER 2 CASES
        // IF SUBSTRING IS ODD, THERE IS 1 MIDDLE ELEMENT i
        // IF SUBSTRING IS EVEN, THERE IS 2 MIDDLE ELEMENTS, i and i+1
        // FIND MAX POSSIBLE PALINDROME SUBSTRING FOR BOTH CASES AND UPADTE MAXLEN
        for(int i=0;i<s.length();i++){
            int oddSize = solve(s,i,i);
            int evenSize = solve(s,i,i+1);
            
            if(oddSize > maxLen){
                maxLen = oddSize;
                maxLeft = i-(maxLen/2);
            }
            
            if(evenSize > maxLen){
                maxLen = evenSize;
                maxLeft = i-(maxLen/2)+1;
            }
        }
        
        return s.substr(maxLeft,maxLen);
    }
};