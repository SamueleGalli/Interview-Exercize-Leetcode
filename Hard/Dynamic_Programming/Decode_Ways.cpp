/*
You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

"1" -> 'A'
"2" -> 'B'
...
"25" -> 'Y'
"26" -> 'Z'

However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

For example, "11106" can be decoded into:

    * "AAJF" with the grouping (1, 1, 10, 6)
    * "KJF" with the grouping (11, 10, 6)
    * The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).

Note: there may be strings that are impossible to decode.

Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.

The test cases are generated so that the answer fits in a 32-bit integer.



Example 1:

Input: s = "12"

Output: 2

Explanation:

"12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: s = "226"

Output: 3

Explanation:

"226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Example 3:

Input: s = "06"

Output: 0

Explanation:

"06" cannot be mapped to "F" because of the leading zero ("6" is different from "06"). In this case, the string is not a valid encoding, so return 0.



Constraints:

    * 1 <= s.length <= 100
    * s contains only digits and may contain leading zero(s).

*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    int to_num(size_t i, size_t w, string s)
    {
        int num = 0;

        num = num * 10 + (s[i] - '0');
        if (w == 2 && i + 1 < s.size() && num != 0)
            num = num * 10 + (s[i + 1] - '0');
        return (num);
    }
    int decode_string(string s, vector<int> &memo, size_t i = 0)
    {
        if (i == s.size())
            return (1);
        if (memo[i] != -1)
            return (memo[i]);

        int total = 0;
        int num = to_num(i, 1, s);
        int num2 = to_num(i, 2, s);

        if (num > 0 && num < 27)
            total += decode_string(s, memo, i + 1);
        if (num2 > 0 && num2 < 27 && i + 1 < s.size())
            total += decode_string(s, memo, i + 2);

        memo[i] = total;
        return (total);
    }
    int numDecodings(string s)
    {
        vector<int> memo(s.size(), -1);
        return (decode_string(s, memo));
    }
};

int main()
{
    Solution s;
    int result;
    string decode;

    decode = "1201234";
    result = s.numDecodings(decode);
    cout << "result = " << result << "\n-----------------------------------------------\n";

    decode = "226";
    result = s.numDecodings(decode);
    cout << "result = " << result << "\n-----------------------------------------------\n";

    decode = "12";
    result = s.numDecodings(decode);
    cout << "result = " << result << "\n-----------------------------------------------\n";

    decode = "06";
    result = s.numDecodings(decode);
    cout << "result = " << result << "\n-----------------------------------------------\n";

    decode = "0";
    result = s.numDecodings(decode);
    cout << "result = " << result << "\n-----------------------------------------------\n";

    decode = "1";
    result = s.numDecodings(decode);
    cout << "result = " << result << "\n-----------------------------------------------\n";

    decode = "2";
    result = s.numDecodings(decode);
    cout << "result = " << result << "\n-----------------------------------------------\n";

    decode = "10";
    result = s.numDecodings(decode);
    cout << "result = " << result << "\n-----------------------------------------------\n";

    decode = "111111111111111111111111111111111111111111111";
    result = s.numDecodings(decode);
    cout << "result = " << result << "\n-----------------------------------------------\n";
}