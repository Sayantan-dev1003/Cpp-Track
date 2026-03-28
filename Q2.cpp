#include <bits/stdc++.h>
using namespace std;

// Node for doubly linked list
class Node
{
public:
    int key;
    string value;
    time_t ttl;
    time_t timestamp;
    Node *prev;
    Node *next;

    Node(int k, string v, int t)
    {
        key = k;
        value = v;
        ttl = t;
        timestamp = time(0);
        prev = next = NULL;
    }
};

// LRU Cache implementation
class LRUCache
{
    int capacity;
    unordered_map<int, Node *> mp;
    Node *head;
    Node *tail;
    int current_time = 0;

public:
    LRUCache(int cap)
    {
        capacity = cap;
        head = new Node(0, "", 0);
        tail = new Node(0, "", 0);
        head->next = tail;
        tail->prev = head;
    }

    // Removes node from DLL
    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Adds node after head (most recent)
    void add(Node *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Checks if entry expired
    bool expired(Node *node)
    {
        return time(0) + current_time >= time(0) + node->ttl;
    }

    // Retrieves value from cache
    string get(int key)
    {
        if (!mp.count(key))
        {
            current_time++;

            return "-1";
        }

        Node *node = mp[key];

        if (expired(node))
        {
            mp.erase(key);
            remove(node);
            current_time++;

            return "-1";
        }

        // Move node to front
        remove(node);
        add(node);
        current_time++;

        return node->value;
    }

    // Inserts or updates cache entry
    void put(int key, string value, int ttl)
    {
        if (mp.count(key))
        {
            Node *node = mp[key];
            node->value = value;
            node->ttl = ttl;
            node->timestamp = time(0);

            remove(node);
            add(node);
            current_time++;
            return;
        }

        // Evict least recently used if needed
        if (mp.size() >= capacity)
        {
            Node *lru = head->next;
            remove(lru);
            mp.erase(lru->key);
        }

        Node *node = new Node(key, value, ttl);
        mp[key] = node;
        add(node);
        current_time++;
    }

    // Displays cache content
    void display()
    {
        Node *curr = tail->prev;
        while (curr != head)
        {
            cout << curr->key << " ";
            curr = curr->prev;
        }
        cout << endl;
    }
};

int main()
{
    LRUCache cache(3);

    cache.put(1, "A", 5);
    cache.put(2, "B", 5);
    cache.put(3, "C", 5);

    cout << cache.get(1) << endl;

    cache.put(4, "D", 5);

    cout << cache.get(2) << endl;
    cache.display();
}