class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        for(int i = 0; i < 31; ++i) {
            if(n & 1)
                ++reversed;

            n >>= 1;
            reversed <<= 1;
        }

        if(n & 1)
            ++reversed;

        return reversed;
    }
};