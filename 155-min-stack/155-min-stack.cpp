class MinStack {
public:
    stack<int> s;
    deque<int> dq;
    
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if(dq.empty() || val <= dq[0]){
            dq.push_front(val);
        }
    }
    
    void pop() {
        int num = s.top();
        s.pop();
        if(num == dq[0]){
            dq.pop_front();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return dq[0];
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