#include <cmath>
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return (false);
        long int max = std::pow(3,19);
        if (max % n == 0)
            return (true);
        return (false);
    }
};