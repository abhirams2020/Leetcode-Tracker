class MinStack {
public:
    stack<int> s;
    deque<int> dq;
    int min = INT_MAX;
    
    MinStack() {
        dq.push_front(min);
    }
    
    void push(int val) {
        s.push(val);
        if(val <= min){
            dq.push_front(val);
            min = val;
        }
    }
    
    void pop() {
        int num = s.top();
        s.pop();
        if(num == min){
            dq.pop_front();
            min = dq[0];
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */