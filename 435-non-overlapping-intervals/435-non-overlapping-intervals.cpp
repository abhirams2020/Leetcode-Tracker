class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        
        // sort elements wrt end index to remove min no of intervals
        // to remove max no of intervals, sort by start index
        sort(intervals.begin(),intervals.end(),comp);
        vector<int> prev = {INT_MIN,INT_MIN};
        
        for(int i=0;i<n;i++){
            if(prev[1]>intervals[i][0]){
                count++;
            }
            else {
                prev = intervals[i];
            }
        }
        
        return count;
    }
};