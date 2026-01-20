/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    * I can be placed before V (5) and X (10) to make 4 and 9. 
    * X can be placed before L (50) and C (100) to make 40 and 90. 
    * C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

 

Constraints:

    * 1 <= s.length <= 15
    * s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    * It is guaranteed that s is a valid roman numeral in the range [1, 3999].


*/

#include <string>

class Solution {
    private:
        int get_double_symbol(char s, int sum)
        {
            int result = 0;
            if (s == 'M')
                result = 1000;
            if (s == 'D')
                result = 500;
            if (s == 'C')
                result = 100;
            if (s == 'L')
                result = 50;
            if (s == 'X')
                result = 10;
            if (s == 'V')
                result = 5;
            if (s == 'I')
                result = 1;
            result = sum - result;
            return (result);
        }
        int get_symbol(char s)
        {
            if (s == 'M')
                return(1000);
            if (s == 'D')
                return(500);
            if (s == 'C')
                return(100);
            if (s == 'L')
                return(50);
            if (s == 'X')
                return(10);
            if (s == 'V')
                return(5);
            if (s == 'I')
                return(1);
            return(0);
        }
        int valid_roman(char s, char s2)
        {
            if (s == 'I' && (s2 == 'V'|| s2 == 'X'))
                return (0);
            if (s == 'X' && (s2 == 'L' || s2 == 'C'))
                return(0);
            if (s == 'C' && (s2 == 'D' || s2 == 'M'))
                return(0);
            return (1);

        }
public:
    int romanToInt(std::string s) {
        int result = 0;
        for (int i = 0;s[i] != 0; i++)
        {
            if (s[i + 1] != 0 && valid_roman(s[i], s[i+ 1]) == 0)
            {
                result += get_double_symbol(s[i], get_symbol(s[i+1]));
                i++;
            }
            else
                result += get_symbol(s[i]);
        }
        return(result);
    }
};