class Solution {
public:
    // mapping of a course to its prerequisites
    unordered_map<int,vector<int>> mp;
    // visited set for checking if node visited again during dfs
    // 0 -> node not visited
    // 1 -> node visited
    // 2 -> node visited and the course can be taken
    vector<int> visited;
    
    bool isCycle(int curr, vector<int> &ans){
        // if curr visited again means curr is starting of cycle
        if(visited[curr]==1){
            return true;
        }
        // if curr element is valid subject and it has visited before
        if(visited[curr]==2){
            return false;
        }
        
        // backtracking
        // current node is added to visited list
        visited[curr] = 1;
        for(auto i:mp[curr]){
            if(isCycle(i,ans)){
                return true;
            }
            else {
                // since no cycles found for i, add to noCycle set
                visited[i] = 2;
            }
        }
        // since no cycles found for curr, visited[curr] = 2
        visited[curr] = 2;
        
        // since curr is visited and can be completed, add to ans
        // curr added after visiting child nodes to get reverse order
        ans.push_back(curr);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // initialise all nodes to 0 meaning unvisited
        visited.resize(numCourses,0);
        vector<int> ans;
        // total number of courses is numCourses -> from 0 to n-1
        // assing empty vector to all courses at first, then add prerequisites to the courses
        for(int i=0;i<numCourses;i++){
            mp[i] = {};
        }
        for(auto i:prerequisites){
            mp[i[0]].push_back(i[1]);
        }
        // DFS with backtracking to check if the graph contains cycle
        for(int i=0;i<numCourses;i++){
            if(isCycle(i,ans)){
                return {};
            }
        }
        return ans;
    }
};