/*
Flatten Nested List Iterator

You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.

Implement the NestedIterator class:

    NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with the nested list nestedList.
    int next() Returns the next integer in the nested list.
    boolean hasNext() Returns true if there are still some integers in the nested list and false otherwise.

Your code will be tested with the following pseudocode:

initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res

If res matches the expected flattened list, then your code will be judged as correct.



Example 1:

Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:

Input: nestedList = [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].


* // This is the interface that allows for creating nested lists.
* // You should not implement it, or speculate about its implementation
* class NestedInteger {
*   public:
*     // Return true if this NestedInteger holds a single integer, rather than a nested list.
*     bool isInteger() const;
*
*     // Return the single integer that this NestedInteger holds, if it holds a single integer
*     // The result is undefined if this NestedInteger holds a nested list
*     int getInteger() const;
*
*     // Return the nested list that this NestedInteger holds, if it holds a nested list
*     // The result is undefined if this NestedInteger holds a single integer
*     const vector<NestedInteger> &getList() const;
* };



* Your NestedIterator object will be instantiated and called as such:
* NestedIterator i(nestedList);
* while (i.hasNext()) cout << i.next();


Constraints:

    * 1 <= nestedList.length <= 500
    * The values of the integers in the nested list is in the range [-10^6, 10^6].
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class NestedInteger
{
    bool is_int;
    int value;
    vector<NestedInteger> list;

public:
    NestedInteger() : is_int(false)
    {
    }
    NestedInteger(int val) : is_int(true), value(val)
    {
    }
    NestedInteger(const vector<NestedInteger> &lst) : is_int(false), list(lst)
    {
    }
    bool isInteger() const
    {
        return is_int;
    }

    int getInteger() const
    {
        return value;
    }

    const vector<NestedInteger> &getList() const
    {
        return list;
    }
};

class NestedIterator
{
private:
    size_t start;
    vector<int> flattened;

    vector<int> flat_list(const vector<NestedInteger> &nestedList)
    {
        vector<int> result;
        for (size_t i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger() == true)
                result.push_back(nestedList[i].getInteger());
            else
            {
                vector<int> temp = flat_list(nestedList[i].getList());
                result.insert(result.end(), temp.begin(), temp.end());
            }
        }
        return (result);
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        flattened = flat_list(nestedList);
        start = 0;
    }

    int next()
    {
        if (start < flattened.size())
        {
            int element = flattened[start];
            start++;
            return (element);
        }
        return (0);
    }

    bool hasNext()
    {
        if (start < flattened.size())
            return (true);
        else
            return (false);
    }
};

void test_list(NestedIterator nested)
{

    while (nested.hasNext())
    {
        cout << nested.next() << " ";
    }
    cout << endl;
}

int main()
{
    {
        vector<NestedInteger> nestedList = {
            NestedInteger(1),
            NestedInteger(vector<NestedInteger>{
                NestedInteger(2),
                NestedInteger(vector<NestedInteger>{
                    NestedInteger(3)})}),
            NestedInteger(4)};

        NestedIterator nested(nestedList);

        test_list(nested);
    }
    {

        vector<NestedInteger> nestedList = {
            NestedInteger(5),
            NestedInteger(6),
            NestedInteger(7)};

        NestedIterator nested(nestedList);

        test_list(nested);
    }
    {
        vector<NestedInteger> nestedList = {
            NestedInteger(vector<NestedInteger>{
                NestedInteger(1),
                NestedInteger(vector<NestedInteger>{
                    NestedInteger(2),
                    NestedInteger(3)}),
                NestedInteger(4)}),
            NestedInteger(5)};

        NestedIterator nested(nestedList);

        test_list(nested);
    }
    {
        vector<NestedInteger> nestedList = {
            NestedInteger(1),
            NestedInteger(vector<NestedInteger>{}),
            NestedInteger(2)};

        NestedIterator nested(nestedList);

        test_list(nested);
    }
    {
        vector<NestedInteger> nestedList = {
            NestedInteger(vector<NestedInteger>{
                NestedInteger(vector<NestedInteger>{
                    NestedInteger(vector<NestedInteger>{
                        NestedInteger(1)})})})};

        NestedIterator nested(nestedList);

        test_list(nested);
    }
}