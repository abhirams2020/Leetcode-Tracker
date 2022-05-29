class Solution {
public:
    // USING MONOTONIC STACK
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            // pop all elements less than or equal to element to be pushed
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            
            // if stack is empty,no result so we keep original value 0
            // if stack not empty, we can calculate the no of days
            if(!st.empty()){
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};