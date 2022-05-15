class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxVol = INT_MIN;
        int l=0,r=n-1;
        while(l<r) {
            // area is width*heighth. we take min of left and right height.
            int vol = min(height[l],height[r]) * (r-l);
            maxVol = max(maxVol, vol);
            
            // we move the lower height to get the max vol
            // if both height same, the max with h is that. so move l and r.
            if(height[l]<height[r]){
                l++;
            }
            else if(height[l]>height[r]){
                r--;
            }
            else {
                l++;
                r--;
            }
        }
        return maxVol;
    }
};