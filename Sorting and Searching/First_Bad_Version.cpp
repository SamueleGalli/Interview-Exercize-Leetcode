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