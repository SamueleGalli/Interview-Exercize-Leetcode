#include <vector>
#include <string>

class Solution
{
private:
    void loop_nums(std::vector<std::vector<int>> &solution, std::vector<int> &parzial, const std::vector<int> nums, std::vector<bool> &used)
    {
        if (parzial.size() == nums.size())
        {
            solution.push_back(parzial);
            return;
        }
        for (size_t i = 0;i < nums.size();i++)
        {
            if (used[i] == false)
            {
                parzial.push_back(nums[i]);
                used[i] = true;
                loop_nums(solution, parzial, nums, used);
                used[i] = false;
                parzial.pop_back();
            }
        }
        return;
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> solution;
        std::vector<int> parzial;
        std::vector<bool> used(nums.size(), false);
        loop_nums(solution, parzial, nums, used);
        return (solution);
    }
};