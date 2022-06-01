class DetectSquares {
public:
    map<pair<int,int>,int> mp;
    
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int ans = 0;
        int x = point[0], y = point[1];
        for(auto i:mp){
            int x1 = i.first.first, y1 = i.first.second;
            if(x==x1 && y==y1){
                continue;
            }
            if(abs(x1-x)==abs(y1-y) && mp.count({x,y1}) && mp.count({x1,y})){
                int c1 = mp[{x1,y1}];
                int c2 = mp[{x,y1}];
                int c3 = mp[{x1,y}];
                ans += c1*c2*c3;
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */