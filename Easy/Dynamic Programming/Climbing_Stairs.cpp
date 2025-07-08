class Solution {
public:
    int climbStairs(int n) {
        if (n < 3)
            return (n);
        int count = 0;
        int step1 = 1;
        int step2 = 2;
        int i = 3;
        while (i <= n)
        {
            count = step1 + step2;
            step1 = step2;
            step2 = count;
            i++;
        }
        return (count);
    }
};