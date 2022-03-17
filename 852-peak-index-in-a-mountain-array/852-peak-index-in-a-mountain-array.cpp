class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(mid!=0 && mid!=n-1 && arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid]){
                return mid;
            }
            else if(mid!=0 && arr[mid-1]>arr[mid]){
                r = mid-1;
            }
            else if(mid!=n-1 && arr[mid+1]>arr[mid]){
                l = mid+1;
            }
        }
        return 0;
    }
};