class Solution {
public:
//      //O(N) space
//      int trap(vector<int>& height) {
//         int left=0, right=0, sum=0, n = height.size();
//         vector<int> maxLeft(n), maxRight(n);
        
//         maxLeft[0] = height[0];
//         maxRight[n-1] = height[n-1];
        
//         for(int i=1;i<n;i++){
//             maxLeft[i] = max(height[i],maxLeft[i-1]);
//             maxRight[n-1-i] = max(height[n-1-i],maxRight[n-i]);
//         }
        
//         for(int i=0;i<n;i++){
//             sum += min(maxLeft[i],maxRight[i]) - height[i];
//         }
//         return sum;
//     }
    
//  O(1) space two pointer approach
    int trap(vector<int>& height) {
        int left=0, right=height.size()-1;
        int maxLeft=0, maxRight=0;
        int water = 0;
        
        while(left < right){
            if(height[left] < height[right]){
                maxLeft = max(maxLeft,height[left]);
                water += maxLeft-height[left];
                left++;
            }
            else {
                maxRight = max(maxRight,height[right]);
                water += maxRight-height[right];
                right--;
            }
        }
        
        return water;
    }
};