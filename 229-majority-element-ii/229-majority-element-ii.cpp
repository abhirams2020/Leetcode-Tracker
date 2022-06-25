class Solution {
public:
    // check if the majority element we got is actually majority    
    bool isMajority(vector<int> &nums, int maj){
        int count = 0;
        for(auto i:nums){
            if(i==maj){
                count++;
            }
        }
        return count > nums.size()/3;
    }
    
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        // at most there will be 2 numbers with count more than n/3
        int maj1 = -1, maj2 = -1;
        int count1 = 0, count2 = 0;
        for(auto i:nums){
            if(maj1==i){
                count1++;
            }
            else if(maj2==i){
                count2++;
            }
            else if(count1==0){
                maj1 = i;
                count1 = 1;
            }
            else if(count2==0){
                maj2 = i;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        if(isMajority(nums,maj1)){
            res.push_back(maj1);
        }
        if(maj1!=maj2 && isMajority(nums,maj2)){
            res.push_back(maj2);
        }
        return res;
    }
};