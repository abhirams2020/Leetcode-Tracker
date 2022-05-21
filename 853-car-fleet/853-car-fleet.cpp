class Solution {
public:
    // Sort cars by descending order of position
    // if a car behind curr car reaches before curr car, means they meet at some point
    // when cars meet, take min of the speeds. so max of time taken is considered
    // if stack empty or stack.top() > curr_time. i.e. ahead car time taken to reach target is more,
    // then they meet once and can be considered as a fleet. 
    // In this case, we take min speed or the max time taken to reach target which is stack.top() itself
    // If stack.top() < curr_time, ie ahead car is faster, then push curr_time to stack
    // For every car, if it meets the car ahead it should get the speed of the ahead car
    // So, if a car is following another car and will not meet, we add the following car speed.
    // The speed of the following car is made the speed of cars behind it if they meet.
    
    // eg.  If A,B,C are  following each other and time taken to reach target in the order C,A,B
    //      then the order of reaching target will be 1st..A  2nd..B&C. Since B is ahead of C, when both meet
    //      speed of B is taken by C and it reaches the target along with B.
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> nums;
        stack<double> time;
        int n = position.size();
        for(int i=0;i<n;i++){
            nums.push_back({position[i],speed[i]});
        }
    
        sort(nums.begin(),nums.end(),greater<>());
        
        for(int i=0;i<n;i++){
            double timeRem = ((double)target-nums[i].first)/nums[i].second;
            if(time.empty()){
                time.push(timeRem);
            }
            else {
                if(time.top() < timeRem){
                    time.push(timeRem);
                }
            }
        }
        return time.size();
    }
};