class LRUCache {
private:
    int size;
    // mp stores key and address of that key in list
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    // list acts as key,value pair. front is most recent.
    list<pair<int,int>> li;
public:
    // when an element in list is accessed, call used fn to move it to front
    void used(int key, int value){
        li.erase(mp[key]);
        li.push_front({key,value});
        mp[key] = li.begin();
    }
    
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)){
            // if mp contains key, update the list and return mp value
            used(key,mp[key]->second);
            return mp[key]->second;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            // if key found in mp, update the list and mp value
            used(key,value);
        }
        else {
            if(mp.size()==size){
                // if list is full, remove least recently used element
                mp.erase(li.back().first);
                li.pop_back();
            }
            li.push_front({key,value});
            mp[key] = li.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */