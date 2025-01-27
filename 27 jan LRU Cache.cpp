class LRUCache {
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
public:
    LRUCache(int cap) : capacity(cap) {}
    int get(int key) {
        if (!map.count(key)) return -1;
        cache.splice(cache.begin(), cache, map[key]); // Move the accessed node to the front
        return map[key]->second;
    }
    void put(int key, int value) {
        if (map.count(key)) cache.splice(cache.begin(), cache, map[key]), map[key]->second = value;
        else {
            if (cache.size() == capacity) map.erase(cache.back().first), cache.pop_back();
            cache.emplace_front(key, value), map[key] = cache.begin();
        }
    }
};