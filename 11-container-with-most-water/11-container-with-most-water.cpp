class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int maxVol = 0;
        
        while(left<right){
            // area is width*heighth. we take min of left and right height.
            int currVol = min(height[left],height[right]) * (right-left);
            maxVol = max(currVol, maxVol);
            
            // we move the lower height to get the max vol
            // if both height same, the max with h is that. so move l and r.
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