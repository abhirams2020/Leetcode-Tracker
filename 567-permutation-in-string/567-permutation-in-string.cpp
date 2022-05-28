class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp1,mp2;
        for(auto i:s1){
            mp1[i]++;
        }
        int l=0;
        for(int r=0;r<s2.length();r++){
            mp2[s2[r]]++;
            
            // compare mp1 and mp2 when window size same as s1.length()
            if(r-l+1 == s1.length()){
                if(mp1==mp2){
                    return true;
                }
                mp2[s2[l]]--;
                if(mp2[s2[l]]==0){
                    mp2.erase(s2[l]);
                }
                l++;
            }
        }
        return false;
    }
};