class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp1, mp2;
        for(auto i:s1){
            mp1[i]++;
        }
        int l=0, r=0;
        for(r=0; r<s2.length(); r++) {
            mp2[s2[r]]++;
            if(r-l+1 == s1.length()) {
                if(mp1 == mp2){
                    return true;
                }
                
                // move left ptr
                mp2[s2[l]]--;
                if(mp2[s2[l]] == 0){
                    mp2.erase(s2[l]);
                }
                l++;
            }
        }
        return false;
    }
};