class Solution {
public:
    // mapping of a prerequisites to its course
    unordered_map<int,vector<int>> mp;
    // visited set for checking if node visited again during dfs
    // 0 -> node not visited
    // 1 -> node visited
    // 2 -> node visited and the course can be taken
    vector<int> visited;
    
    bool isCycle(int curr){
        // backtracking
        // current node is added to visited list
        visited[curr] = 1;
        for(auto i:mp[curr]){
            if(visited[i]==0){
                if(isCycle(i)){
                    return true;
                }
            }
            // i has been visited before, cycle exist
            else if(visited[i]==1){
                return true;
            }
        }
        // since no cycles found for curr, visited[curr] = 2
        visited[curr] = 2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // initialise all nodes to 0 meaning unvisited
        visited.resize(numCourses,0);
        // total number of courses is numCourses -> from 0 to n-1
        // assing empty vector to all courses at first, then add courses to the prerequisites
        for(int i=0;i<numCourses;i++){
            mp[i] = {};
        }
        for(auto i:prerequisites){
            mp[i[1]].push_back(i[0]);
        }
        // DFS with backtracking to check if the graph contains cycle
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(isCycle(i)){
                    return false;
                }
            }
        }
        return true;
    }
};