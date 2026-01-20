/*
Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:

Input: n = 0
Output: 0

Example 3:

Input: n = 1
Output: 0

 

Constraints:

    * 0 <= n <= 5 * 10^6


*/
#include <vector>
#include <iterator>

class Solution {
private:
    std::vector<int> give_nums(int max, int i)
    {
        std::vector<int> prime;
        while (i <= max)
        {
            prime.push_back(i);
            i++;
        }
        return (prime);
    }
public:
    int countPrimes(int n) {
        if (n <= 1)
            return (0);
        std::vector<int> prime = give_nums(n, 2);
        for (size_t i = 0; i < prime.size(); i++)
        {
            if (prime[i] == 0)
                continue;
            int multiply = prime[i];
            for (size_t j = i + multiply; j < prime.size();j = j + multiply)
            {
                prime[j] = 0;
            }
        }
        int c_prime = 0;
        for (size_t i = 0; i < prime.size() - 1; i++)
        {
            if (prime[i] != 0)
                c_prime++;
        }
        return (c_prime);
    }
};