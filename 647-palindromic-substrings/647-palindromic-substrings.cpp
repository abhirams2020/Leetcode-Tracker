class Solution {
public:
    int countPal(string &s, int l, int r){
        int count = 0;
        while(l>=0 && r<s.length() && s[l]==s[r]){
            count++;
            l--;
            r++;
        }
        return count;
    }
    
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0;i<s.length();i++){
            count = count + countPal(s,i,i) + countPal(s,i,i+1);
        }
        return count;
    }
};