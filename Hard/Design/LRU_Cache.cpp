/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.



Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4


Your LRUCache object will be instantiated and called as such:
LRUCache* obj = new LRUCache(capacity);
int param_1 = obj->get(key);
obj->put(key,value);

Constraints:

    * 1 <= capacity <= 3000
    * 0 <= key <= 10^4
    * 0 <= value <= 10^5
    * At most 2 * 10^5 calls will be made to get and put.

*/

using namespace std;

#include <iostream>
#include <unordered_map>

struct chace_list
{
    int val;
    int key;

    chace_list *prev;
    chace_list *next;
    chace_list()
    {
        val = -1;
        key = -1;
        next = nullptr;
        prev = nullptr;
    }
};

void print_list(chace_list *list)
{
    chace_list *head = list;
    int size = 0;
    cout << "\n---------------------------------------------------------------\n";
    cout << "\n\n(";
    while (head)
    {
        cout << "{" << head->key << ", " << head->val << "}, ";
        size++;
        head = head->next;
    }
    cout << ")\n\n";
    cout << "la sua dimensione attuale e " << size << endl;
    cout << "\n---------------------------------------------------------------\n";
}

class LRUCache
{
private:
    unordered_map<int, chace_list *> chace;
    chace_list *l_chace;
    chace_list *tail_chace;

    void get_chace(chace_list *node)
    {
        if (node == tail_chace)
            return;

        if (node->prev)
            node->prev->next = node->next;
        else
            l_chace = node->next;
        if (node->next)
            node->next->prev = node->prev;
        else
            tail_chace = node->prev;

        node->next = nullptr;
        node->prev = tail_chace;
        tail_chace->next = node;
        tail_chace = node;
        l_chace->prev = nullptr;
    }

public:
    LRUCache(int capacity)
    {

        chace_list *temp = nullptr;
        chace_list *prev_head = nullptr;

        l_chace = new chace_list();

        chace_list *head = l_chace;
        for (int i = 1; i < capacity; i++)
        {
            temp = new chace_list();
            head->next = temp;
            prev_head = head;
            head = head->next;
            head->prev = prev_head;
        }
        tail_chace = head;
    }

    int get(int key)
    {
        if (chace.count(key))
        {
            this->get_chace(chace[key]);
            chace_list *temp = chace[key];
            return (temp->val);
        }
        else
            return (-1);
    }

    void put(int key, int value)
    {
        if (chace.count(key))
        {
            chace_list *temp = chace[key];
            temp->val = value;
        }
        else
        {
            if (l_chace->key != -1)
                chace.erase(l_chace->key);
            l_chace->key = key;
            l_chace->val = value;
            chace[key] = l_chace;
        }
        this->get_chace(chace[key]);
    }
    ~LRUCache()
    {
        chace_list *temp = nullptr;
        while (l_chace)
        {
            temp = l_chace;
            l_chace = l_chace->next;
            delete temp;
        }
        l_chace = nullptr;
    }
};

int main()
{
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(2, 1);
    lRUCache->put(3, 2);
    cout << "Cerco chiave 3 =" << lRUCache->get(3) << endl;
    cout << "Cerco chiave 2 =" << lRUCache->get(2) << endl;
    lRUCache->put(4, 3);
    cout << "Cerco chiave 2 =" << lRUCache->get(2) << endl;
    cout << "Cerco chiave 3 =" << lRUCache->get(3) << endl;
    cout << "Cerco chiave 4 =" << lRUCache->get(4) << endl;
    delete lRUCache;
}