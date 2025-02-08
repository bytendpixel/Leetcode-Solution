class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int count = 0;
        while (n != 0) {
            res = res << 1;
            if (n & 1) res = res | 1;
            n = n >> 1;
            count ++;
        }

        while (count < 32) {
            res = res << 1;
            count++;
        }

        return res;
    }
};
