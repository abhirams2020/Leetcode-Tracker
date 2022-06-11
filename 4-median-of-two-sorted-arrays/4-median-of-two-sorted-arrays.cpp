class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid = (nums1.size()+nums2.size())/ 2;
        double prev_m=0, m=0;
        int f1=0,f2=0;
        while(mid+1>0 && f1<nums1.size() && f2<nums2.size()){
            if(nums1[f1] < nums2[f2]){
                prev_m = m;
                m = nums1[f1];
                f1++;
            }
            else {
                prev_m = m;
                m = nums2[f2]; 
                f2++;
            }
            mid--;
        }
        while(mid+1>0 && f1<nums1.size()){
            prev_m = m;
            m = nums1[f1];
            f1++;
            mid--;
        }
        while(mid+1>0 && f2<nums2.size()){
            prev_m = m;
            m = nums2[f2]; 
            f2++;
            mid--;
        }
        if((nums1.size()+nums2.size())% 2 == 0){
            return (prev_m + m)/2;
        }
        return m;
    }
};