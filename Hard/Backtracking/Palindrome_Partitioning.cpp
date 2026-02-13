/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.



Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:

Input: s = "a"
Output: [["a"]]



Constraints:

    * 1 <= s.length <= 16
    * s contains only lowercase English letters.


*/

using namespace std;

#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    bool valid(string s)
    {
        size_t i = 0;
        size_t j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return (false);
            i++;
            j--;
        }
        return (true);
    }
    void palyndromer(vector<vector<string>> &polyndrom, string s, size_t i, vector<string> &level_pol)
    {
        string word;
        if (i == s.size())
        {
            polyndrom.push_back(level_pol);
            return;
        }

        for (size_t count = 1; count <= s.size() - i; count++)
        {
            word = s.substr(i, count);
            if (valid(word))
            {
                level_pol.push_back(word);
                palyndromer(polyndrom, s, i + count, level_pol);
                level_pol.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> polyndrom;
        vector<string> level_pol;
        palyndromer(polyndrom, s, 0, level_pol);
        return (polyndrom);
    }
};

void print_me_string(vector<vector<string>> result)
{
    cout << "\n-------------------------------------------------------\n";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << i << " cicle\n";
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << "result[" << i << "][" << j << "] = " << result[i][j] << endl;
        }
    }
    cout << "\n-------------------------------------------------------\n";
}

int main()
{
    Solution s;
    vector<vector<string>> result;
    string poli;

    poli = "aab";
    result = s.partition(poli);
    print_me_string(result);

    poli = "a";
    result = s.partition(poli);
    print_me_string(result);

    poli = "bb";
    result = s.partition(poli);
    print_me_string(result);

    poli = "cdd";
    result = s.partition(poli);
    print_me_string(result);

    poli = "efe";
    result = s.partition(poli);
    print_me_string(result);
    poli = "anna";
    result = s.partition(poli);
    print_me_string(result);
}