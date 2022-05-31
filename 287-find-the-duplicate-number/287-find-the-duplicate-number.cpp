class Solution {
public:
    // // there are n+1 numbers in range [1,n].
    // // when a number is found. make nums[abs(number)] to negative
    // // negative at index i indicates i was found before
    // int findDuplicate(vector<int>& nums) {
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[abs(nums[i])] < 0){
    //             return abs(nums[i]);
    //         }
    //         nums[abs(nums[i])] = -(nums[abs(nums[i])]);
    //     }
    //     return -1;
    // }
    
    // using linked list cycle concept
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0], slow = nums[0];
        
        // loop till we find the cycle
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(fast == slow){
                break;
            }
        }
        
        // find start of cycle by pointing slow to start of list
        slow = nums[0];
        while(fast!=slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};