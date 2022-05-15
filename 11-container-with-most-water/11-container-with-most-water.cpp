class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxVol = INT_MIN;
        int l=0,r=n-1;
        while(l<r) {
            int vol = min(height[l],height[r]) * (r-l);
            maxVol = max(maxVol, vol);
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