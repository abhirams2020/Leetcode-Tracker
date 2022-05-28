class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int left = 0, right = n-1;
        while(left < right){
            while(left<n && !isalnum(s[left])){
                left++;
            }
            while(right>=0 && !isalnum(s[right])){
                right--;
            }
            if(left<right && tolower(s[left])!=tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};