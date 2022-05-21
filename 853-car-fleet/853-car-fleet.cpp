class Solution {
public:
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