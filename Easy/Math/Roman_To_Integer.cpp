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