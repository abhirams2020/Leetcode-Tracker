class Solution {
public:
//     // sort the intervals after inserting new interval and merge them
    
//     vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals){
//         sort(intervals.begin(), intervals.end());
//         vector<int> prev;
//         vector<vector<int>> res;
//         prev = intervals[0];
//         for(int i=1;i<intervals.size();i++){
//             if(intervals[i][0] > prev[1]){
//                 res.push_back(prev);
//                 prev = intervals[i];
//             }
//             else {
//                 prev[1] = max(intervals[i][1], prev[1]);
//             }
//         }
//         res.push_back(prev);
//         return res;
//     }
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         vector<int> prev;
//         vector<vector<int>> res;
        
//         bool found = false;
        
//         for(int i=0;i<intervals.size();i++){
//             if(intervals[i][0]<=newInterval[0] && intervals[i][1]>=newInterval[0]){
//                 intervals[i][1] = max(intervals[i][1], newInterval[1]);
//                 found = true;
//                 break;
//             }
//         }
//         // if no overlapping inteval found, insert new interval in intervals and merge
//         if(found == false){
//             intervals.push_back(newInterval);
//         }
//         return mergeIntervals(intervals);
//     }
    
   // sort the intervals after inserting new interval and merge them
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> prev(2);
        vector<vector<int>> res;
        int n = intervals.size();
        bool found = false;
        int i=0;
        // add all intervals to res which end before start of newInterval
        while(i<n && intervals[i][1]<newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }
        
        // current interval overlaps which new interval, so change curr interval
        prev = newInterval;
        
        // merge intervals till end of prev is less than start of curr
        while(i<n && prev[1]>=intervals[i][0]){
            prev[0] = min(intervals[i][0], prev[0]);
            prev[1] = max(intervals[i][1], prev[1]);
            i++;
        }
        // push the resulting prev after merging
        res.push_back(prev);
        // add remaining intervals to result
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};