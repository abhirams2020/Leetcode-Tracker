class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        
        // FINDING NEAREST SMALLER TO LEFT
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                left[i] = -1;
            }
            else {
                left[i] = s.top();
            }
            s.push(i);
        }
        
        // CLEAR THE STACK
        // while(!s.empty()){
        //     s.pop();
        // }
        s = {};
        
        // FINDING NEAREST SMALLER TO RIGHT
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                right[i] = n;
            }
            else {
                right[i] = s.top();
            }
            s.push(i);
        }
        
        // CALCULATE MAX AREA
        //--------------------
        // LEFT CONTAINS POSITION OF NEAREST SMALLER ELEMENT TO LEFT
        // RIGHT CONTAINS POSITION OF NEAREST SMALLER ELEMENT TO RIGHT
        
        // AREA = heights[i] * (DISTANCE BETWEEN RIGHT AND LEFT)
        // DISTANCE = R-L+1. R is right[i]-1. L is left[i]+1
        // DISTANCE = right[i]-1-left[i]-1+1 = right[i]-left[i]-1
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int currArea = heights[i] * (right[i] - left[i] - 1);
            maxArea = max(maxArea, currArea);
        }
        
        return maxArea;
    }
};