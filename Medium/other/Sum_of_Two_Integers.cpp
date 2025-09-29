class Solution {
public:
    int getSum(int a, int b) {
        int result;
        while (b != 0)
        {
            result = a ^ b;
            b = (a & b) << 1;
            a = result;
        }
        return result;
    }
};