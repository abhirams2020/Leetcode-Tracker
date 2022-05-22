class Solution {
public:
//     bool dfs(unordered_map<int, vector<int>> graph, int source, int destination, unordered_set<int>& visited){
//         if(source == destination){
//             return true;
//         }
//         visited.insert(source);
//         for(auto i:graph[source]){
//             if(!visited.count(i) && dfs(graph,i,destination,visited)){
//                 return true;
//             }
//         }
//         return false;
//     }
    
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         unordered_map<int, vector<int>> graph;
//         for(auto node:edges){
//             graph[node[0]].push_back(node[1]);
//             graph[node[1]].push_back(node[0]);
//         }
//         unordered_set<int> visited;
//         return dfs(graph,source,destination,visited);
//     }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int,vector<int>> graph; 
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,0);        
        stack<int> st;
        st.push(start);
        visited[start] = 1; 
        
        while(!st.empty()){ 
            auto top = st.top();
            if(top == end)
                return 1;
            st.pop();
            for(auto node : graph[top]){
                if(!visited[node]){
                    visited[node] = 1;
                    st.push(node); 
                }
            }
        }
        return false;
    }
};