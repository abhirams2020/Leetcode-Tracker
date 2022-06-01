class Solution {
public:
    int getSum(int a, int b) {
        // store sum in a and carry in b
        while(b!=0){
            int sum = a^b;
            int carry = (a&b);
            a = sum;
            b = ((unsigned int)carry)<<1;
        }
        return a;
    }
};