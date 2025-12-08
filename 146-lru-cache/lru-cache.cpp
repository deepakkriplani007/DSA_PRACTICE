class LRUCache {
public:
        list<pair<int,int>>cache;
        unordered_map<int,list<pair<int,int>>::iterator>mp;
        int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        int val=-1;
        if(mp.find(key)!=mp.end()){
        list<pair<int,int>>::iterator curr=mp[key];
        val=(*curr).second;
        mp.erase(key);
        cache.erase(curr);
        put(key,val);
        }
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
        list<pair<int,int>>::iterator curr=mp[key];
        mp.erase(key);
        cache.erase(curr);
        }
        if(mp.size()==cap){
            mp.erase(cache.back().first);
            cache.pop_back();
        }
        cache.push_front({key,value});
        mp[key]=cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */