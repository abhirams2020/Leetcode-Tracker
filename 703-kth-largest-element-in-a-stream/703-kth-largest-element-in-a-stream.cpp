class KthLargest {
public:
    // instead of creating minheap -> priority_queue<int, vector<int>, greater<>> pq
    // push -value into the pq and display -ve of top() value
    // same functioning as minheap
    priority_queue<int> pq;
    int size;
    
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(auto i:nums){
            pq.push(-i);
            while(pq.size() > k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(-1*val);
        while(pq.size() > size){
            pq.pop();
        }
        return -1*pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */