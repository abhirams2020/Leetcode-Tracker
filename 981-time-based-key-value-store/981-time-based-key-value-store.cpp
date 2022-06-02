class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mp;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    // search highest value less than or equal to timestamp
    string searchVal(vector<pair<int,string>> &arr, int timestamp){
        int l = 0, r = arr.size()-1;
        int last = -1; // storing last occurrance of valid value
        while(l<=r){
            int mid = (l+r)/2;
            if(arr[mid].first <= timestamp){
                last = mid;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }

        if(last==-1){
            return ""; // no valid value found
        }
        return arr[last].second;
    }
    
    string get(string key, int timestamp) {
        if(mp.count(key)==0){
            return "";
        }
        return searchVal(mp[key],timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */