#include <iostream>
#include <list>
#include <vector>
using namespace std;

class MyHashMap {
private:
    static const int SIZE = 10007;
    vector<list<pair<int, int>>> table;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        table.resize(SIZE);
    }

    void put(int key, int value) {
        int idx = hash(key);
        for (auto& kv : table[idx]) {
            if (kv.first == key) {
                kv.second = value;
                return;
            }
        }
        table[idx].push_back({key, value});
    }

    int get(int key) {
        int idx = hash(key);
        for (const auto& kv : table[idx]) {
            if (kv.first == key) return kv.second;
        }
        return -1;
    }

    void remove(int key) {
        int idx = hash(key);
        table[idx].remove_if([key](const pair<int, int>& kv) {
            return kv.first == key;
        });
    }
};