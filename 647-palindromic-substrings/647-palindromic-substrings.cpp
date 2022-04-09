class Solution {
public:
    
    int countPal(string &s, int l, int r){
        int count=0;
        while(l>=0 && r<s.length()){
            if(s[l]!=s[r]){
                break;
            }
            count++;
            l--;
            r++;
        }
        return count;
    }
    
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0;i<s.length();i++){
            ans += countPal(s,i,i) + countPal(s,i,i+1);
        }
        return ans;
    }
};