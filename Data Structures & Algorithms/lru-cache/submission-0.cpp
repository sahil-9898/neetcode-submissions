class LRUCache {

private:
    int capacity;
    vector<pair<int, int>> cache;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        for (int i=0;i<cache.size();i++) {
            pair<int, int> p = cache[i];
            if (p.first == key) {
                cache.erase(cache.begin() + i);
                cache.push_back(p);
                return p.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for (int i=0;i<cache.size();i++) {
            pair<int, int> p = cache[i];
            if (p.first == key) {
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }
        if (cache.size() == capacity) {
            cache.erase(cache.begin());
        }
        cache.push_back({key, value});
        return;
    }
};
