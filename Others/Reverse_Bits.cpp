#include <stdint.h>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        int i = 0;
        while (i < 32)
        {
            reversed = reversed << 1;
            reversed = reversed | (n & 1);
            n >>= 1;
            i++;
        }
        return (reversed);
    }
};