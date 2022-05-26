class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        
        for(int i=n-1;i>=0;i--){
            // KEEP MAKING 9 TO 0 TILL WE GET NO LESS THAN 9
            // INCREMENT THAT NO BY 1 AND RETURN THE VECTOR
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            else {
                digits[i]=0;
            }
        }
        
        // IF ALL DIGITS ARE 9, WE NEED TO ADD 1 IN FRONT
        
        // digits.push(digits.begin(),1);
        digits[0] = 1;
        digits.push_back(0);
        
        return digits;
    }
};