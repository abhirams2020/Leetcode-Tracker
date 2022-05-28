class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 1;
        char maxChar = s[0];
        vector<int> mp(256,0);
        
        int l=0;
        for(int r=0;r<s.length();r++){
            mp[s[r]]++;
            
            // if count of s[r] >= count of maxChar, update maxChar
            
            // eg. s=BAAA,k=0. 
            // if i=1 count of A,B are same.If not updated, mp['B'] becomes 0 but (r-l+1)-mp[maxChar] = 1.
            // So it will remove 'A' also. If we updated maxChar to 'A' while adding 'A', this would not happen.
            if(mp[s[r]]>=mp[maxChar]){
                maxChar = s[r];
            }
            
            // we don't need loop to update maxChar since maxcount in the window is count[maxChar].
            // when we move l to right, the maximum of counts remains less than the maxcount.
            while((r-l+1)-mp[maxChar] > k){
                cout<<s[l]<<endl;
                mp[s[l]]--;
                l++;
            }
            
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};