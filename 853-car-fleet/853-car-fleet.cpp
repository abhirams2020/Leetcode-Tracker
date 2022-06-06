class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int,float>> pq;
        for(int i=0;i<position.size();i++){
            float time = (target-position[i])/(float)speed[i];
            pq.push({position[i], time});
        }
        int count = 0;
        while(!pq.empty()){
            float currTime = pq.top().second;
            while(!pq.empty() && pq.top().second<=currTime){
                pq.pop();
            }
            count++;
        }
        return count;
    }
};