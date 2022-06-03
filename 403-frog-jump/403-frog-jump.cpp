class Solution {
public:
    // dp[i][j] stores result for j jump from an index i
    vector<vector<int>> dp;
    // map to check if curr dist is valid index and get index from dist
    unordered_map<int,int> mp;
    
    bool solve(vector<int> &stones, int dist, int jump){
        // if curr pos is not valid or jump is 0
        dist = dist+jump;
        if(mp.count(dist)==0 || jump==0){
            return false;
        }
        int index = mp[dist];
        // if index reaches last pos
        if(index == stones.size()-1){
            return true;
        }
        if(dp[index][jump]!=-1){
            return dp[index][jump];
        }
        return dp[index][jump] = (solve(stones,dist,jump-1) || solve(stones,dist,jump) || solve(stones,dist,jump+1));
    }
    
    bool canCross(vector<int>& stones) {
        // max jump possible is size of array
        dp.resize(stones.size(), vector<int> (stones.size(), -1));
        // initial jump should be from 0 to 1.
        int jump = 1;
        for(int i=0;i<stones.size();i++){
            mp[stones[i]] = i;
        }
        return solve(stones, 0, jump);
    }
};