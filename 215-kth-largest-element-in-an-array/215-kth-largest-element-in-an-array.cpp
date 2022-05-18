class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto i:nums){
            // if we push i, it is maxheap. so push -i
            pq.push(-i);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return -1*pq.top();
    }
};