class TimeMap {
public:
    map<pair<int,string>, string> mp;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[{timestamp,key}] = value;
        // cout<<mp[{timestamp,key}]<<endl;
    }
    
    string get(string key, int timestamp) {
        for(int i=timestamp;i>=1;i--){
            if(mp.find({i,key})!=mp.end()){
                return mp[{i,key}];
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */