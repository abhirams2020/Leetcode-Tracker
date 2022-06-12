class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int> prev;
        vector<vector<int>> res;
        prev = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] > prev[1]){
                res.push_back(prev);
                prev = intervals[i];
            }
            else {
                prev[1] = max(intervals[i][1], prev[1]);
            }
        }
        res.push_back(prev);
        return res;
    }
};