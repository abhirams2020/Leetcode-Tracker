class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int maxVol = 0;
        
        while(left<right){
            int currVol = min(height[left],height[right]) * (right-left);
            maxVol = max(currVol, maxVol);
            
            if(height[left]==height[right]){
                left++;
                right--;
            }
            else if(height[left]<height[right]){
                left++;
            }
            else {
                right--;
            }
        }
        
        return maxVol;
    }
};