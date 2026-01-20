/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

 

Example 1:

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.

Example 2:

Input: n = 1, bad = 1
Output: 1

 

Constraints:

    * 1 <= bad <= n <= 2^31 - 1


*/

bool isBadVersion(int version)
{
    if (version >= 4)
        return true;
    return false;
}

class Solution
{
public:
    int firstBadVersion(int n)
    {
        long int start = 1;
        long int half;
        while (start < n)
        {
            half = (start + n) / 2;
            if (isBadVersion(half)  == true)
                n = half;
            else
                start = half + 1;
        }
        return (start);
    }
};