class Solution {
public:
//     O(N) space
//     int trap(vector<int>& height) {
//         int left=0, right=0, sum=0, n = height.size();
//         vector<int> maxLeft(n), maxRight(n);
        
//         for(int i=0;i<n;i++){
//             left = max(height[i],left);
//             maxLeft[i] = left;
//         }
        
//         for(int i=n-1; i>=0;i--){
//             right = max(height[i],right);
//             maxRight[i] = right;
//         }
    
//         for(int i=0;i<n;i++){
//             sum += min(maxLeft[i],maxRight[i]) - height[i];
//         }
//         return sum;
//     }
    
//  O(1) space two pointer approach
    int trap(vector<int>& height) {
        int maxLeft=0, maxRight=0, sum=0;
        int left=0, right=height.size()-1;
        
        while(left < right){
            if(height[left] < height[right]){
                maxLeft = max(maxLeft, height[left]);
                sum += maxLeft - height[left];
                left++;
            }
            else {
                maxRight = max(maxRight, height[right]);
                sum += maxRight - height[right];
                right--;
            }
        }
        
        return sum;
    }
};