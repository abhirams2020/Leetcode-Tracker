class Solution {
private:
    vector<vector<int>> res;
    
public:
    void permute(vector<int> &nums, int index){
        if(index==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index], nums[i]);
            permute(nums, index+1);
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        permute(nums,0);
        return res;
    }
};