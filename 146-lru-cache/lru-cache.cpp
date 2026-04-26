class LRUCache {
public:
    int cap;
    
    // DLL → stores {key, value}
    list<pair<int,int>> l;
    
    // key → iterator in list
    unordered_map<int, list<pair<int,int>>::iterator> mp;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // not found
        if (mp.find(key) == mp.end()) return -1;

        // move node to front (most recently used)
        l.splice(l.begin(), l, mp[key]);

        return mp[key]->second;
    }
    
    void put(int key, int value) {
        // if key exists
        if (mp.find(key) != mp.end()) {
            // update value
            mp[key]->second = value;

            // move to front
            l.splice(l.begin(), l, mp[key]);
        } 
        else {
            // if capacity full → remove LRU (back)
            if (l.size() == cap) {
                auto last = l.back();   // {key, value}
                mp.erase(last.first);
                l.pop_back();
            }

            // insert new node at front
            l.push_front({key, value});
            mp[key] = l.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */