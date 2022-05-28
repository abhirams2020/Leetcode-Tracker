class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> count;
        priority_queue<pair<int,int>> pq;
        
        for(auto i:nums){
            count[i]++;
        }
        
        for(auto i:count){
            pq.push({i.second,i.first});
        }
        
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};