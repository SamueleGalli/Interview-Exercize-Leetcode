#include <vector>

class Solution
{
private:
    void swap_current(std::vector<int> &nums, size_t i, int &type)
    {
        size_t j = i;
        int temp = nums[i];
        while (count_type(type,nums,i) == 0)
            type++;
        while (j < nums.size())
        {
            if (nums[j] == type)
                break;
            j++;
        }
        if (j == nums.size())
            return;
        nums[i] = nums[j];
        nums[j] = temp;
    }
    int count_type(int type, std::vector<int> nums, size_t i)
    {
        int count = 0;
        while (i < nums.size())
        {
            if (nums[i] == type)
                count++;
            i++;
        }
        return (count);
    }

public:
    void sortColors(std::vector<int> &nums)
    {
        int type = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (type != nums[i])
                swap_current(nums,i, type);
        }
    }
};