class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        
        for(int i=n-1;i>=0;i--){
            digits[i] = (digits[i]+1)%10;
            if(digits[i]!=0){
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};