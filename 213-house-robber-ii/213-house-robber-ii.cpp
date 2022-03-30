class Solution {
public:
    
    int dp[2][100];
    
    int solve(vector<int> &nums, int i, int index){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[i][index]!=-1){
            cout<<i<<" "<<index<<" "<<dp[i][index]<<endl;
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
        vector<int> v1(nums.begin() + 1, nums.end());
        vector<int> v2(nums.begin(), nums.end() - 1);
        return max(solve(v1,0,0),solve(v2,1,0));
    }
};