class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        // no of elements in left partition of the merged array
        int half = (n1 + n2)/2;
        int left = 0 , right = n1-1;
        while(true){
            int m1 = floor((left+right)/2.0);
            int m2 = half - m1 - 2;
            
            int l1 = (m1<0)?INT_MIN:nums1[m1];
            int l2 = (m2<0)?INT_MIN:nums2[m2];
            int r1 = (m1+1>=n1)?INT_MAX:nums1[m1+1];
            int r2 = (m2+1>=n2)?INT_MAX:nums2[m2+1];
            // cout<<m1<<" "<<m2<<endl;
            // cout<<l1<<" "<<r2<<" : "<<l2<<" "<<r1<<endl;
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2 == 0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                return min(r1,r2);
            }
            else if(l1>r2){
                right = m1-1;
            }
            else if(l2>r1){
                left = m1+1;
            }
        }
        return 0;
    }
};