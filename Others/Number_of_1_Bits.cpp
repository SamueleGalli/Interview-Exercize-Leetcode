class Solution {
public:
    int hammingWeight(int n) {
        int bit = 0;
        while (n > 0)
        {
            n = n & (n - 1);
            bit++;
        }
        return(bit);
    }
};