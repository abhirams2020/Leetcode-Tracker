class Solution {
public:
    // there are n+1 numbers in range [1,n].
    // when a number is found. make nums[number] to negative
    // negative at index i indicates i was found before
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])] < 0){
                return abs(nums[i]);
            }
            nums[abs(nums[i])] = -(nums[abs(nums[i])]);
        }
        return -1;
    }
};