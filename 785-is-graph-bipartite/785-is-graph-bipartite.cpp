class Solution {
public:
    unordered_map<int,vector<int>> adj;
    vector<int> visited;
    
    bool check(int node){
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            int parent_color = visited[curr];
            int child_color = !parent_color;
            for(auto i:adj[curr]){
                if(visited[i]==-1){
                    q.push(i);
                    visited[i] = child_color;
                }
                else if(visited[i]==parent_color){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        visited.resize(n,-1);
        
        for(int i=0;i<n;i++){
            adj[i] = {};
        }
        
        for(int i=0;i<n;i++){
            for(auto node:graph[i]){
                adj[i].push_back(node);
            }
        }
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(check(i)==false){
                    return false;
                }
            }
        }
        return true;
    }
};