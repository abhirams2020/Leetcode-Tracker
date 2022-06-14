class Solution {
public:
    typedef pair<int,int> pii;
    
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> q = queries;
        sort(intervals.begin(),intervals.end());
        sort(q.begin(),q.end());
        // unordered map to store min size for a given num
        unordered_map<int,int> mp;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        int i = 0;
        for(auto num:q){
            // keep only elements valid for curr num in the pq
            // valid means end should be greater than or equal to num
            // if intervals from previous num is valid, keep that (IMP)
            while(!pq.empty() && pq.top().second < num){
                pq.pop();
            }
            
            while(i<intervals.size()){
                int start = intervals[i][0], end = intervals[i][1];
                // if start > num, means all intervals from now is invalid. so break
                if(start>num){
                    break;
                }
                // if end < num, means num not in this interval
                if(num<=end){
                    pq.push({end-start+1, end});
                }
                i++;
            }
            // pq is empty means no valid intervals found
            if(pq.empty()){
                mp[num] = -1;
            }
            // pq.top() stores valid interval with least size
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