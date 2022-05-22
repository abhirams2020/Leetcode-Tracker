class Solution {
public:
    bool dfs(vector<vector<int>> &graph, int source, int destination, vector<int>& visited){
        if(source == destination){
            return true;
        }
        visited[source] = 1;
        for(auto i:graph[source]){
            if(visited[i]==0 && dfs(graph,i,destination,visited)){
                return true;
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto node:edges){
            graph[node[0]].push_back(node[1]);
            graph[node[1]].push_back(node[0]);
        }
        vector<int> visited(n,0);
        return dfs(graph,source,destination,visited);
    }
};