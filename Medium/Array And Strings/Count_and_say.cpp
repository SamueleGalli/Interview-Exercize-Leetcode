#include <iostream>

class Solution {
    private:
        char count(std::string temp, int j)
        {
            int count = 1;
            while(temp[j] != 0 && temp[j + 1] != 0 && temp[j] == temp[j + 1])
            {
                count++;
                j++;
            }
            char counted = count + '0';
            return(counted);
        }
public:
    std::string countAndSay(int n) {
        if (n == 1)
            return ("1");
        std::string tot ;
        std::string temp = "1";
        for (int i = 1;i < n; i++)
        {
            for (int j = 0; temp[j] != 0;j++)
            {
                if (j == 0)
                    tot = "";
                if (j > 0 && temp[j] == temp[j - 1])
                    continue;
                tot = tot + count(temp, j) + temp[j];
            }
            temp = tot;
        }
        return (tot);
    }
};