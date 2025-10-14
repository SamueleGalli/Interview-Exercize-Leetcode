#include <vector>

using namespace std;

class Solution
{
private:
    int min(int n1, int n2)
    {
        if (n1 < n2)
            return (n1);
        return (n2);
    }

public:
    int maxArea(vector<int> &height)
    {
        size_t j = height.size() - 1;
        int max_area = 0;
        int water_height = 0;
        int temp_calc = 0;
        for (size_t i = 0; i < height.size();)
        {
            water_height = height[j];
            temp_calc = min(water_height, height[i]) * (j - i);
            if (temp_calc > max_area)
                max_area =  temp_calc;
            if (height[i] > height[j])
                j--;
            else
                i++;
        }
        return (max_area);
    }
};
