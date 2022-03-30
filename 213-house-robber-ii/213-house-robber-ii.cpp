class Solution {
public:
    
    int dp[2][100];
    
    int solve(vector<int> &nums, int i, int index){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[i][index]!=-1){
            return dp[i][index];
        }
        // include nums[index] and move to index+2 OR not include nums[index] and move to index+1
        return dp[i][index] = max(solve(nums,i,index+1) ,nums[index] + solve(nums,i,index+2));
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        memset(dp,-1,sizeof(dp));
        vector<int> v1,v2;
        for(int i=1;i<nums.size();i++){
            v1.push_back(nums[i]);
        }
        for(int i=0;i<nums.size()-1;i++){
            v2.push_back(nums[i]);
        }
        return max(solve(v1,0,0),solve(v2,1,0));
    }
};