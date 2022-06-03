class Solution {
public:
    vector<vector<int>> dp;
    unordered_map<int,int> mp;
    
    bool solve(vector<int> &stones, int dist, int jump){
        if(mp.count(dist)==0 || jump==0){
            return false;
        }
        int index = mp[dist];
        if(index == stones.size()-1){
            return true;
        }
        if(dp[index][jump]!=-1){
            return dp[index][jump];
        }
        dist = dist+jump;
        return dp[index][jump] = (solve(stones,dist,jump-1) || solve(stones,dist,jump) || solve(stones,dist,jump+1));
    }
    
    bool canCross(vector<int>& stones) {
        dp.resize(stones.size(), vector<int> (stones.size(), -1));
        // initial jump should be from 0 to 1.
        int jump = 1;
        for(int i=0;i<stones.size();i++){
            mp[stones[i]] = i;
        }
        return solve(stones, 0, jump);
    }
};