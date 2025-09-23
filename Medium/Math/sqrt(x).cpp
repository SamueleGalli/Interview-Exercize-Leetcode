using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return (0);
        long int better_x = x;
        for (long int i = 1; i < better_x;i++)
        {
            if (i * i == better_x)
                return (i);
            else if (i * i > better_x)
                return (--i);
        }
        return (1);
    }
};