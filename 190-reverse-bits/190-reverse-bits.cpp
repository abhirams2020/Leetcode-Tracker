class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        // since 32 digits are there, we repeat 32 times
        // each time add unit digit to ans and move it left by 1 place
        // move n to right by 1 place
        // instead of adding to ans, we can also use OR for speed.
        // we do ans<<1 first since at last digit we should not do ans<<1
        for(int i=0;i<32;i++){
            ans = ans<<1;
            ans = ans | (n&1); // ans + (n&1)
            n = n>>1;
        }
        return ans;
    }
};