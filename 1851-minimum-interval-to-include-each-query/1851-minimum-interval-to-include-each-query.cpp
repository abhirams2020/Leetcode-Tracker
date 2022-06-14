class Solution {
public:
    typedef pair<int,int> pii;
    
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> q = queries;
        sort(intervals.begin(),intervals.end());
        sort(q.begin(),q.end());
        unordered_map<int,int> mp;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int i = 0;
        for(auto num:q){
            while(!pq.empty() && pq.top().second < num){
                pq.pop();
            }
            
            while(i < intervals.size()){
                int start = intervals[i][0], end = intervals[i][1];
                if(start>num){
                    break;
                }
                if(end>=num){
                    pq.push({end-start+1, end});
                }
                i++;
            }
            if(pq.empty()){
                mp[num] = -1;
            }
            else {
                mp[num] = pq.top().first;
            }
        }
        vector<int> res;
        for(auto i:queries){
            res.push_back(mp[i]);
        }
        return res;
    }
};