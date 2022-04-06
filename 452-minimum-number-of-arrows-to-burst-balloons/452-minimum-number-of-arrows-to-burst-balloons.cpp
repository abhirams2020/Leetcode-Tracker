class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        // minEnd is the last y index encountered so far.
        // only if new pair has y greater than minEnd, we can consider it.
        int ans = 0;
        int minEnd = INT_MAX;
        for(int i=0;i<points.size();i++){
            if(ans == 0 || minEnd<points[i][0]){
                ans += 1;
                minEnd = points[i][1];
            }
            else {
                minEnd = min(minEnd,points[i][1]);
            }
        }
        return ans;
    }
};