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
    
    // USING DEQUE (OPTIMAL SOLN)
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
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};