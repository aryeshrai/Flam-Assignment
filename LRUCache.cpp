#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int cap;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        auto it = cache[key];
        int val = it->second;
        lru.erase(it);
        lru.push_front({key, val});
        cache[key] = lru.begin();
        return val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            lru.erase(cache[key]);
        }
        lru.push_front({key, value});
        cache[key] = lru.begin();

        if (lru.size() > cap) {
            int old_key = lru.back().first;
            cache.erase(old_key);
            lru.pop_back();
        }
    }
};