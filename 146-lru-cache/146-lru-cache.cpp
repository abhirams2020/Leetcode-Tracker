class LRUCache {
private:
    int size;
    // mp stores key and address of that key in list
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    // list acts as key,value pair. front is most recent.
    list<pair<int,int>> li;
public:
    // when an element in list is accessed, call used fn to move it to front
    void moveToFront(int key, int value){
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
            moveToFront(key,mp[key]->second);
            return mp[key]->second;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            // if key found in mp, update the list and mp value
            moveToFront(key,value);
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

/*
Algorithm Outline:

LRUCache()
1. key -> (addr, value)
2. List, will contain keys
3. cap=capacity

Get
1. if found, movetofirst for key, return. Else -1

Put
1. if exist, update.
2. else add
3. move to first
4. if >capacity, remove last in list i.e. LRU

Move to first
1. erase element
2. add to first
3. store first addr in ht
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */