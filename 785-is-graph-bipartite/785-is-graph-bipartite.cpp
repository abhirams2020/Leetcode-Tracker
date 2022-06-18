class Solution {
public:
    // colors array to keep track of visited nodes
    //  0 = not visited
    // -1 = visited and red color
    //  1 = visited and blue color
    vector<int> colors;
    
    // BFS traversal
    bool checkBFS(vector<vector<int>>& adj, int node){
        queue<int> q;
        q.push(node);
        colors[node] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            int parent_color = colors[curr];
            int child_color = -parent_color;
            for(auto i:adj[curr]){
                // if colors unvisited, push to queue and assing color
                if(colors[i]==0){
                    q.push(i);
                    colors[i] = child_color;
                }
                else if(colors[i]==parent_color){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool checkDFS(vector<vector<int>>& adj, int node){
        int parent_color = colors[node];
        for(auto i:adj[node]){
            if(colors[i]==0){
                colors[i] = -parent_color;
                if(checkDFS(adj,i)==false){
                    return false;
                }
            }
            else if(colors[i]==parent_color){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        colors.resize(n,0);
        
        for(int i=0;i<n;i++){
            // if i was not visited, do bfs on it
            if(colors[i]==0){
                colors[i] = 1;
                if(checkDFS(graph,i)==false){
                    return false;
                }
            }
        }
        return true;
    }
};