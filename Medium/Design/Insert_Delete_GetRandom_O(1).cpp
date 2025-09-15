#include <vector>
#include <set>
#include <iterator>

using namespace std;

class RandomizedSet
{
public:
    set<int> numbers;
    RandomizedSet()
    {
        srand(time(0));
    }

    bool insert(int val)
    {
        auto result = numbers.insert(val);
        return result.second;
    }

    bool remove(int val)
    {
        if (numbers.erase(val) == 1)
            return true;
        return false;
    }

    int getRandom()
    {
        size_t r_numb = rand() % numbers.size();
        auto index = numbers.begin();
        advance(index, r_numb);
        return (*index);
    }
};