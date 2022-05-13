class Solution {
public:
    int trap(vector<int>& height) {
        int left=0, right=0, sum=0, n = height.size();
        vector<int> maxLeft(n), maxRight(n);
        
        for(int i=0;i<n;i++){
            left = max(height[i],left);
            maxLeft[i] = left;
        }
        
        for(int i=n-1; i>=0;i--){
            right = max(height[i],right);
            maxRight[i] = right;
        }
        
        for(int i=0;i<n;i++){
            sum += min(maxLeft[i],maxRight[i]) - height[i];
        }
        
        return sum;
    }
};