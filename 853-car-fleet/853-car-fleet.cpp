class Solution {
public:
    // Sort cars by descending order of position
    // if a car behind curr car reaches before curr car, means they meet at some point
    // when cars meet, take min of the speeds. so max of time taken is considered
    // For every car, if it meets the car ahead it should get the speed of the ahead car
    
    // if time taken by car behind curr is less than time taken by curr, they will arrive as a fleet
    // remove all pos behind curr which has time<=curr time till time>currtime. 
    // All these will be single fleet. Then increment count.
    // repeat till the priority queue is empty
    
    // eg.  If A,B,C are  following each other and time taken to reach target in the order C,A,B
    //      then the order of reaching target will be 1st..A  2nd..B&C. Since B is ahead of C, when both meet
    //      speed of B is taken by C and it reaches the target along with B.
    
    // int carFleet(int target, vector<int>& position, vector<int>& speed) {
    //     // priority queue to store {position, time}
    //     priority_queue<pair<int,double>> pq;
    //     for(int i=0;i<position.size();i++){
    //         double time = (target-position[i])/(double)speed[i];
    //         pq.push({position[i], time});
    //     }
    //     int count = 0;
    //     while(!pq.empty()){
    //         double currTime = pq.top().second;
    //         while(!pq.empty() && pq.top().second<=currTime){
    //             pq.pop();
    //         }
    //         count++;
    //     }
    //     return count;
    // }
    static bool comp(pair<int,double> &a, pair<int,double> &b) {
        return a.first < b.first;
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> posTime;
        int count = 0;
        for(int i=0;i<position.size();i++){
            double time = (double)(target - position[i])/speed[i];
            posTime.push_back({position[i],time});            
        }
        sort(posTime.begin(),posTime.end(),comp);
        int i=position.size()-1;
        while(i>=0){
            double currTime = posTime[i].second;
            while(i>=0 && posTime[i].second <= currTime){
                i--;
            }
            count++;
        }
        return count;
    }
};