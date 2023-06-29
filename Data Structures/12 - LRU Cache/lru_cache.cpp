#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class LRUCache {
    int capacity;
    map<int, int> m;
    list<int> l;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->m.clear();
        this->l.clear();
    }

    void put(int key, int value);
    int get(int key);
};

void LRUCache::put(int key, int value) {
    // See if it exists first

    if(m.find(key) == m.end()) {
    // Here, key doesn't exist
    
        // If capacity is exceeded,
        // pop the least used from list
        // and erase from map
        if(l.size() == this->capacity) {
            m.erase(l.back());
            l.pop_back();
        }
        
        m[key] = value;
        l.push_front(key);
    } else {
    // Here, key does already exist.
    // Move the key to the front of the list 
    // and update its value in the map

        l.remove(key);
        l.push_front(key);
        m[key] = value;
    }
}

int LRUCache::get(int key) {
    if(m.find(key) == m.end()) {
        return -1;
    } else {
        int value = m[key];
        l.remove(key);
        l.push_front(key);
        return value;
    }
}

int main() {
    LRUCache lru(2);

    lru.put(1, 1);
    lru.put(2, 2);
    lru.put(3, 3);
    lru.put(4, 4);
    cout << lru.get(3) << endl;
    lru.put(2, 2);
    cout << lru.get(4) << endl;
    cout << lru.get(2) << endl;
    
    return 0;
}