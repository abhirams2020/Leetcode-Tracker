class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int,double>> pq;
        for(int i=0;i<position.size();i++){
            double time = (target-position[i])/(double)speed[i];
            pq.push({position[i], time});
        }
        int count = 0;
        while(!pq.empty()){
            double currTime = pq.top().second;
            while(!pq.empty() && pq.top().second<=currTime){
                pq.pop();
            }
            count++;
        }
        return count;
    }
};