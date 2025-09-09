#include <vector>
#include <algorithm>

class Solution
{
public:
    int coinChange(std::vector<int> &coins, int amount)
    {
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int coin : coins)
            {
                if (i >= coin)
                    dp[i] = std::min(dp[i], 1 + dp[i - coin]);
            }
        }
        if (dp[amount] == amount + 1)
            return -1;
        else
            return (dp[amount]);
    }
};