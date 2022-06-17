class Solution {
public:
    // mapping of a course to its prerequisites
    unordered_map<int,vector<int>> mp;
    // visited set for checking if node visited again during dfs
    unordered_set<int> visited;
    // noCycle set to save valid subjects
    unordered_set<int> noCycle;
    
    bool isCycle(int curr, vector<int> &ans){
        // if curr visited again means curr is starting of cycle
        if(visited.count(curr)){
            return true;
        }
        // if curr element is valid subject, there is no cycle
        if(noCycle.count(curr)){
            return false;
        }
        // backtracking
        visited.insert(curr);
        for(auto i:mp[curr]){
            if(isCycle(i,ans)){
                return true;
            }
            else {
                // since no cycles found for i, add to noCycle set
                noCycle.insert(i);
            }
        }
        ans.push_back(curr);
        visited.erase(curr);
        // since no cycles found for curr, add to noCycle set
        noCycle.insert(curr);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0){
            // Empty prerequisite list => Courses are independent => take the courses in any order
            vector<int> ans;
            for(int i=0;i<numCourses;i++){
                ans.push_back(i);
            }
            return ans;
        }
        for(int i=0;i<numCourses;i++){
            mp[i] = {};
        }
        for(auto i:prerequisites){
            mp[i[0]].push_back(i[1]);
        }
        // DFS with backtracking to check if the graph contains cycle
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(isCycle(i,ans)){
                return {};
            }
        }
        return ans;
    }
};