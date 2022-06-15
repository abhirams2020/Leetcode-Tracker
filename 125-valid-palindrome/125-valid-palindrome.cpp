class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int left = 0, right = n-1;
        while(left < right){
            
            // move left ptr till we find alphanumeric element
            while(left<n && !isalnum(s[left])){
                left++;
            }
            
            // move right ptr till we find alphanumeric elemtnt
            while(right>=0 && !isalnum(s[right])){
                right--;
            }
            
            // if no alphanumeric element is there, left will be greater than right
            if(left<right && tolower(s[left])!=tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};