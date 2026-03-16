class KeyVal {
    public:
        int key;
        int val;
        KeyVal(int key, int val) : key(key), val(val) {}
};

class LRUCache {
public:
    int capacity;
    int elcount;
    std::list<KeyVal> order;
    std::unordered_map<int, std::list<KeyVal>::iterator> lookup;

    LRUCache(int capacity) : capacity(capacity), elcount(0) {}
    
    int get(int key) {
        auto it = lookup.find(key);

        if (it == lookup.end()) {
            return -1;
        }

        KeyVal kv = *(it->second);
        order.erase(it->second);
        order.push_front(kv);
        lookup[kv.key] = order.begin();
        return kv.val;
    }
    
    void put(int key, int value) {
        auto it = lookup.find(key);

        if (it != lookup.end()) {
            KeyVal ret = *(it->second);
            ret.val = value;
            order.erase(it->second);
            order.push_front(ret);
            lookup[ret.key] = order.begin();
            return;
        }

        elcount++;
        
        if (elcount > capacity) {
            auto lru = prev(order.end());
            int key = lru->key;

            order.erase(lru);
            lookup.erase(key);

            elcount--;
        }

        KeyVal new_kv(key, value);
        order.push_front(new_kv);
        lookup[key] = order.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */