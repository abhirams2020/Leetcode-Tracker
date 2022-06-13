class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[1] == b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        
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