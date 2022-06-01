class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        // new ans = ans*10 + digit
        // if new ans overflows INT_MAX, it means ans*10 + digit > INT_MAX
        // there are two possibilities, ans*10 > INT_MAX or ans=INT_MAX/10
        // INT_MAX/10 = 2147483647/10 = 214748364.
        // So for valid ans, last digit should be <= 7.
        while(x){
            int digit = x%10;
            
            if(ans > INT_MAX/10 || (ans==INT_MAX/10 && digit >= INT_MAX%10)){
                return 0;
            }
            if(ans < INT_MIN/10 || (ans==INT_MAX/10 && digit <= INT_MIN%10)){
                return 0;
            }
            
            ans = ans*10 + digit;
            x = x/10;
        }
        return ans;
    }
};