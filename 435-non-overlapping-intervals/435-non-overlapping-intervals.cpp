// // SORTING INTERVALS BY END INDEX

// class Solution {
// public:
//     static bool comp(vector<int>& a, vector<int>& b){
//         return a[1]<b[1];
//     }
    
//     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//         int n = intervals.size();
//         int count = 0;
        
//         // sort elements wrt end index to remove min no of intervals
//         // to remove max no of intervals, sort by start index
//         sort(intervals.begin(),intervals.end(),comp);
//         vector<int> prev = {INT_MIN,INT_MIN};
        
//         for(int i=0;i<n;i++){
//             if(prev[1]>intervals[i][0]){
//                 count++;
//             }
//             else {
//                 prev = intervals[i];
//             }
//         }
        
//         return count;
//     }
// };


// SORTING INTERVALS BY START INDEX

// Case 1:-
// ------------------   -----------------
// |   Interval 1   |   |   Interval 2  |
// ------------------   -----------------

//Case 2:-
// ------------------
// |   Interval 1   |
// ------------------
//            ------------------
//            |    Interval 2  |
//            ------------------

//Case 3:-
//  --------------------
//  |    Interval 1    |
//  --------------------
//     --------------
//     | Interval 2 |
//     --------------

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        int count = 0;
        sort(intervals.begin(),intervals.end());
        vector<int> prev = {INT_MIN,INT_MIN};
        
        for(int i=0;i<n;i++){
            // if intervals dont overlap, change prev to curr and check next interval
            if(prev[1] <= intervals[i][0]){
                prev = intervals[i];
            }
            else {
                // if interval 1 covers interval 2, remove interval 1 to avoid overlap with further intervals
                // else remove interval 2 to avoid overlap with further intervals
                if(prev[1]<=intervals[i][1]){
                    // remove curr interval
                    count++;
                }
                else {
                    // remove prev interal
                    prev = intervals[i];
                    count++;
                }
            }
        }
        return count;
    }
};