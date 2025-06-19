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