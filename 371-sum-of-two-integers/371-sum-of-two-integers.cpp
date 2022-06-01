class Solution {
public:
    int getSum(int a, int b) {
        // store sum in a and carry in b
        // sum of 2 digits can be found by using XOR
        // ie if 0,0 or 1,1 that place sum will be 0. else 1
        // carry is found by doing AND. carry only if both are 1
        // unsigned carry to avoid overflow when negative shift to left
        
        while(b!=0){
            int sum = a^b;
            int carry = a&b;
            a = sum;
            b = ((unsigned int)carry)<<1;
        }
        return a;
    }
};