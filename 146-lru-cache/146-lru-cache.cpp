class LRUCache {
public:
    
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        
        node( int key , int val)
        {
            this->key = key;
            this->val=val;
            this->next=NULL;
            this->prev=NULL;
            
        }
    };

    unordered_map<int,node*>mp;
    int capacity;
   
//two dummy nodes to keep track starting and ending point of list  
    node * head = new node(0,0);
    node * tail = new node(0,0);
    

    
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next=tail;
        tail->prev= head;
        
    }
    
// function to help a node in the next to head [can say front of our list]
    void insert ( node* currnode)
    {
        currnode->next = head->next;                      // adding node in next of head (front of our cache)
        head->next->prev = currnode;
        head->next= currnode;
        currnode->prev= head;
        mp[currnode->key]=currnode;                       //update map accordingly
    }
    
   
// function to remove a node 
    void remove(node* currnode)
    {
        mp.erase(currnode->key);
        currnode->next->prev =currnode->prev;
        currnode->prev->next=currnode->next;
       
    }
  
  
    int get(int key) 
    {
       // if key is not present than return -1;
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        //if key is present , than update the node and return the value associated with the key
        // for update first we remove the node and then add at start of list with the help of insert function
        node *currnode = mp[key];
        remove(currnode);
        insert(currnode);
        return currnode->val;
        
    }
    
    void put(int key, int value)
    {
       //if key is already present than we have to update it 
       // similiary we first remove and then add node in front with the help of insert helper 
        if(mp.find(key)!=mp.end())
        {
            remove(mp[key]);
        }
        
        // if size is full then we have to remove the least recently used node
        if(mp.size()==capacity)
        {
            remove(tail->prev);
        }
        insert(new node(key,value));
        
    }
};

// class LRUCache {
// private:
//     int size;
//     // mp stores key and address of that key in list
//     unordered_map<int,list<pair<int,int>>::iterator> mp;
//     // list acts as key,value pair. front is most recent.
//     list<pair<int,int>> li;
// public:
//     // when an element in list is accessed, call used fn to move it to front
//     void moveToFront(int key, int value){
//         li.erase(mp[key]);
//         li.push_front({key,value});
//         mp[key] = li.begin();
//     }
    
//     LRUCache(int capacity) {
//         size = capacity;
//     }
    
//     int get(int key) {
//         if(mp.count(key)){
//             // if mp contains key, update the list and return mp value
//             moveToFront(key,mp[key]->second);
//             return mp[key]->second;
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         if(mp.count(key)){
//             // if key found in mp, update the list and mp value
//             moveToFront(key,value);
//         }
//         else {
//             if(size == mp.size()){
//                 // if list is full, remove least recently used element
//                 mp.erase(li.back().first);
//                 li.pop_back();
//             }
//             li.push_front({key,value});
//             // begin() - address of front element
//             // front() - value of front element
//             mp[key] = li.begin();
//         }
//     }
// };

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