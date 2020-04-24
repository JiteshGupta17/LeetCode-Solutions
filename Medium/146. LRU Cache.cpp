class LRUCache {
    
    // first of pair is value corresponding to that key and second is iterator to the position on which this key is present in list ordering
    
    unordered_map<int,pair<int,list<int> :: iterator>> mp;
    list<int> ordering;
    
    int ms;
    
    void update(int key)
    {
        auto posi = mp[key].second;
        ordering.erase(posi);
        
        ordering.push_front(key);
        mp[key].second = ordering.begin();
    }
    
public:
    
    LRUCache(int capacity) {
        ms = capacity;
    }
    
    int get(int key) {
        
       if(mp.find(key) != mp.end())
       {
           update(key);
           return mp[key].first;
       }
        return -1;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end())
        {
            update(key);
            mp[key].first = value;
            return;
        }
        
        if(mp.size()==ms)
        {
            mp.erase(ordering.back());
            ordering.pop_back(); 
        }
        
        ordering.push_front(key);
        mp[key] = {value,ordering.begin()};
        
    }
};

