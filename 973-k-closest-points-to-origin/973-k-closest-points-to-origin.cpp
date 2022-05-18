class Solution {
public:
    int dist(int x, int y){
        return x*x + y*y;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<points.size();i++){
            // multiply -1 to dist from origin so that pq works like minheap
            pq.push(make_pair(-1*dist(points[i][0], points[i][1]) ,i));
        }
        
        while(k){
            int n = pq.top().second;
            pq.pop();
            vector<int> temp = {points[n][0], points[n][1]};
            ans.push_back(temp);
            k--;
        }
        return ans;
    }
};