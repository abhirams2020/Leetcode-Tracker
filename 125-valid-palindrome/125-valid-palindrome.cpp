class Solution {
public:
    
    // bool isPalindrome(string s) {
    //     int l=0, r=s.length()-1;
    //     while(l<r){
    //         if(!isalnum(s[l])){
    //             l++;
    //         }
    //         else if(!isalnum(s[r])){
    //             r--;
    //         }
    //         else {
    //             if(tolower(s[l]) != tolower(s[r])){
    //                 return false;
    //             }
    //             l++;
    //             r--;
    //         }
    //     }
    //     return true;
    // }
    
    bool isPalindrome(string s) {
        int l=0, r=s.length()-1;
        while(l < r){
            while(l<s.length() && !isalnum(s[l]))
                l++;
            while(r>0 && !isalnum(s[r]))
                r--;
            if(l<r && tolower(s[l])!=tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};