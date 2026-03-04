/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

    * After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:

Input: prices = [1]
Output: 0



Constraints:

    * 1 <= prices.length <= 5000
    * 0 <= prices[i] <= 1000

*/

using namespace std;

#include <iostream>
#include <vector>
#include <limits.h>

/*
Creare matrice risultati e stato (comprato o meno) credo?
Capire perche funziona dopo la matrice perche facilita la comprensione
*/
class Solution
{
public:
    int get_better_profit(vector<int> &prices, int buy, vector<int> &memo, size_t i = 0)
    {
        if (i >= prices.size())
        {
            cout << "return 0\n\n";
            return (0);
        }

        if (memo[i] != -1)
            return (memo[i]);
        // se ho gia comprato avanzo i + 1
        int skipping;
        int best_offer;

        cout << "mi trovo al prezzo " << prices[i] << endl;
        if (buy == INT_MIN)
        {
            cout << "ora di comprare\n\n";
            // memo su compra
            int taking = get_better_profit(prices, prices[i], memo, i + 1);
            skipping = get_better_profit(prices, INT_MIN, memo, i + 1);
            best_offer = max(taking, skipping);
            //memo[i] = best_offer;
            return (best_offer);
        }
        else
        {
            cout << "ora di vendere\n\n";
            int sold = prices[i] - buy + get_better_profit(prices, INT_MIN, memo, i + 2);
            skipping = get_better_profit(prices, buy, memo, i + 1);
            best_offer = max(sold, skipping);
            memo[i] = best_offer;
            return (best_offer);
        }
    }

    int
    maxProfit(vector<int> &prices)
    {
        vector<int> memo(prices.size(), -1);
        return (get_better_profit(prices, INT_MIN, memo));
    }
};

int main()
{
    Solution s;
    int result;
    vector<int> prices;

    /*prices = {1};
    result = s.maxProfit(prices);
    cout << "---------------------------------------\nresult = (" << result << ")\n";*/

    prices = {1, 2, 3, 4, 5};
    result = s.maxProfit(prices);
    cout << "---------------------------------------\nresult = (" << result << ")\n";

    /*prices = {1, 2, 3, 0, 2};
    result = s.maxProfit(prices);
    cout << "---------------------------------------\nresult = (" << result << ")\n";

    prices = {123, 23, 2, 1, 90};
    result = s.maxProfit(prices);
    cout << "---------------------------------------\nresult = (" << result << ")\n";

    prices = {1, 3, 2, 4};
    result = s.maxProfit(prices);
    cout << "---------------------------------------\nresult = (" << result << ")\n";

    prices = {1, 3, 8, 2, 4, 0, 9};
    result = s.maxProfit(prices);
    cout << "---------------------------------------\nresult = (" << result << ")\n";

    prices = {1, 3, 8, 2, 4, 0, 9, 6, 7, 2, 4, 6};
    result = s.maxProfit(prices);
    cout << "---------------------------------------\nresult = (" << result << ")\n";*/
}