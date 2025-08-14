#include <vector>
#include <string>
class Solution
{
private:

    void create_subset(std::vector<int> nums, std::vector<std::vector<int>> &solution, std::vector<int> &subset, size_t i)
    {
        if (nums.size() == i)
        {
            solution.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        create_subset(nums, solution, subset, i + 1);
        subset.pop_back();
        create_subset(nums, solution, subset, i + 1);
    }

public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> solution;
        std::vector<int> subset;
        create_subset(nums, solution, subset, 0);
        return (solution);
    }
};