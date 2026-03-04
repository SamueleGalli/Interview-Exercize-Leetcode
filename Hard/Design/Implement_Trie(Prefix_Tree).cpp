/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

    * Trie() Initializes the trie object.
    * void insert(String word) Inserts the string word into the trie.
    * boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
    * boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.



Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True



Constraints:

    * 1 <= word.length, prefix.length <= 2000
    * word and prefix consist only of lowercase English letters.
    * At most 3 * 10^4 calls in total will be made to insert, search, and startsWith.


*/

using namespace std;

#include <iostream>
#include <string>

class Trie
{
public:
    bool end_of_word = false;
    Trie *roots[26];

    Trie()
    {
        for (size_t i = 0; i < 26; i++)
            roots[i] = nullptr;
    }

    void insert(string word)
    {
        Trie *current = this;
        int index;
        for (char c : word)
        {
            index = c - 'a';
            if (!current->roots[index])
                current->roots[index] = new Trie();
            current = current->roots[index];
        }
        current->end_of_word = true;
    }

    bool search(string word)
    {
        Trie *current = this;
        int index;
        for (char c : word)
        {
            index = c - 'a';
            if (!current->roots[index])
                return (false);
            current = current->roots[index];
        }
        if (current->end_of_word)
            return (true);
        return (false);
    }

    bool startsWith(string prefix)
    {
        Trie *current = this;
        int index;
        for (char c : prefix)
        {
            index = c - 'a';
            if (!current->roots[index])
                return (false);
            current = current->roots[index];
        }
        return (true);
    }
};

void delete_trie(Trie *&obj)
{
    if (!obj)
        return;

    for (size_t i = 0; i < 26; i++)
    {
        if (obj->roots[i])
            delete_trie(obj->roots[i]);
    }
    delete obj;
    obj = nullptr;
}

int main()
{
    Trie *obj = new Trie();
    obj->insert("apple");
    cout << boolalpha << "operation is = " << obj->search("apple") << endl;
    cout << boolalpha << "operation is = " << obj->search("app") << endl;
    cout << boolalpha << "operation is = " << obj->startsWith("app") << endl;
    obj->insert("app");
    cout << boolalpha << "operation is = " << obj->search("app") << endl;
    delete_trie(obj);
    obj = nullptr;
}