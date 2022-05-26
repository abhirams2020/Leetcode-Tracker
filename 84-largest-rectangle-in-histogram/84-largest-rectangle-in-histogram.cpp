class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = -1;
        right[n-1] = n;
        
        // FINDING NEAREST SMALLER TO LEFT
        for(int i=1;i<n;i++){
            int prev = i-1;
            while(prev>=0 && heights[prev]>=heights[i]){
                prev = left[prev];
            }
            left[i] = prev;
        }
        
        // FINDING NEAREST SMALLER TO RIGHT
        for(int i=n-2;i>=0;i--){
            int prev = i+1;
            while(prev<n && heights[prev]>=heights[i]){
                prev = right[prev];
            }
            right[i] = prev;
        }
        
        // CALCULATE MAX AREA
        //--------------------
        // LEFT CONTAINS POSITION OF NEAREST SMALLER ELEMENT TO LEFT
        // RIGHT CONTAINS POSITION OF NEAREST SMALLER ELEMENT TO RIGHT
        
        // AREA = heights[i] * (DISTANCE BETWEEN RIGHT AND LEFT)
        // WIDTH = R-L+1. R is right[i]-1. L is left[i]+1
        // WIDTH = right[i]-1-left[i]-1+1 = right[i]-left[i]-1
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int currArea = heights[i] * (right[i] - left[i] - 1);
            maxArea = max(maxArea, currArea);
        }
        
        return maxArea;
    }
};