class Solution {
public:
    
    // USING HEAP
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> ans;
    //     priority_queue<pair<int,int>> pq;
    //     int l=0;
    //     for(int r=0;r<nums.size();r++){
    //         pq.push({nums[r],r});
    //         if(r-l+1==k){
    //             while(pq.top().second < l){
    //                 pq.pop();
    //             }
    //             ans.push_back(pq.top().first);
    //             l++;
    //         }
    //     }
    //     return ans;
    // }
    
    // // USING DEQUE WITH PAIR
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> ans;
    //     deque<pair<int,int>> dq;
    //     for(int i=0;i<nums.size();i++){
    //         if(!dq.empty() && dq.front().second <= i-k){
    //             dq.pop_front();
    //         }
    //         while(!dq.empty() && dq.back().first < nums[i]){
    //             dq.pop_back();
    //         }
    //         dq.push_back({nums[i],i});
    //         if(i>=k-1){
    //             ans.push_back(dq.front().first);
    //         }
    //     }
    //     return ans;
    // }
    
    // USING DEQUE WITH INT
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<nums.size();i++){
            // As the window move on, element nums[i-k] will be outdated
            if(!dq.empty() && dq.front() == i-k){
                dq.pop_front();
            }
            
            // We clear all elements less than nums[i] from right of queue to left.
            // This ensure the queue is in decreasing order, i.e. monotonic queue
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            
            // Since the queue is monotonic we know max element is always at front
            if(i+1>=k){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};