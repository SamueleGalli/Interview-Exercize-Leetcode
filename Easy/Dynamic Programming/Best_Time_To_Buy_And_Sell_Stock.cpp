#include <cstddef>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        size_t i;
        int profit = 0;
        int min = prices[0];
        for (i = 1; i < prices.size(); i++)
        {
            if (prices[i] < min)
                min = prices[i];
            if (prices[i] - min > profit)
                profit = prices[i] - min;
        }
        return (profit);
    }
};