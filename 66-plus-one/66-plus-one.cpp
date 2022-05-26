class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        
        for(int i=n-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            else {
                digits[i]=0;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};