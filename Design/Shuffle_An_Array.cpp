#include <vector>
#include <random>
#include <chrono>

class Solution
{
private:
    std::vector<int> origin;

public:
    Solution(std::vector<int> &nums)
    {
        origin = nums;
    }

    std::vector<int> reset()
    {
        return (origin);
    }

    std::vector<int> shuffle()
    {
        if (origin.size() <= 1)
            return origin;
        std::vector<int> copy;
        copy = origin;
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator(seed);
        size_t end;
        for (size_t i = 0; i < copy.size(); i++)
        {
            std::uniform_int_distribution<int> distributin(i, copy.size() - 1);
            end = distributin(generator);
            int copy_val = copy[i];
            copy[i] = copy[end];
            copy[end] = copy_val;
        }
        return(copy);
    }
};
