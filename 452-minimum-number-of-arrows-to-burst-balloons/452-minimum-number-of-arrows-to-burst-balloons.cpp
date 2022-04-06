// class Solution {
// public:
    
//     int findMinArrowShots(vector<vector<int>>& points) {
//         sort(points.begin(),points.end());
//         // minEnd is the last y index encountered so far.
//         // only if new pair has y greater than minEnd, we can consider it.
//         int ans = 1;
//         int minEnd = points[0][1];
//         for(int i=1;i<points.size();i++){
//             if(minEnd<points[i][0]){
//                 ans += 1;
//                 minEnd = points[i][1];
//             }
//             else {
//                 minEnd = min(minEnd,points[i][1]);
//             }
//         }
//         return ans;
//     }
// };


// compare function shows error if declared inside class
bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        // minEnd is the last y index encountered so far.
        // only if new pair has y greater than minEnd, we can consider it.
        int ans = 1;
        int minEnd = points[0][1];
        for(int i=1;i<points.size();i++){
            if(minEnd<points[i][0]){
                ans += 1;
                minEnd = points[i][1];
            }
        }
        return ans;
    }
};