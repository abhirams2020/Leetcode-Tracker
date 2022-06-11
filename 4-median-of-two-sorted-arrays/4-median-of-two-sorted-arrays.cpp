class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        // if n1 < n2, there is possibility for index out of range error
        // eg nums1=[1], nums2=[2,3,4,5]. if we partition using nums2, possible partition is nums2=[][2,3,4,5].
        // in this case nums1 dont have enough numbers to fill the half of merged array.
        // correct partition is [1,2][3,4,5]
        // so binary search only on smallest array
        if(n1 > n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        // no of elements in left partition of the merged array
        int half = (n1 + n2)/2;
        int left = 0 , right = n1;
        while(left<=right){
            // cut denotes start index of right section. left is [0,....,cut1-1]
            int cut1 = (left+right)/2;
            
            // left of nums1 has size=cut1. so nums2 left should have size = half - cut1
            int cut2 = half - cut1;
            
            // if left section empty, make it -inf. if right empty, make it inf.
            int l1 = (cut1-1<0)?INT_MIN:nums1[cut1-1];
            int l2 = (cut2-1<0)?INT_MIN:nums2[cut2-1];
            int r1 = (cut1>=n1)?INT_MAX:nums1[cut1];
            int r2 = (cut2>=n2)?INT_MAX:nums2[cut2];
            
            // partitioning valid if last element of left sections is less than first of right sections
            // we know l1<=r2 and l2<=r2. so check l1<=r2 and l2<=r1
            // since nums1 is list we're doing binary search, move its left and right ptr.
            // if partition valid, return median depending on if its odd or even size array
            // if l1>r2, it means l1 should not be there in the first half of merged arrays, so right = cut1-1
            // if l2>r1, it means we can add more elements from nums1 for finding valid half, so left = cut1+1
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2 == 0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                return min(r1,r2);
            }
            else if(l1>r2){
                right = cut1-1;
            }
            else if(l2>r1){
                left = cut1+1;
            }
        }
        return 0;
    }
};