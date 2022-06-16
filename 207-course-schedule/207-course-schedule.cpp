class Solution {
public:
    unordered_map<int,vector<int>> mp;
    unordered_set<int> visited;
    unordered_set<int> noCycle;
    
    bool isCycle(int curr){
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
            if(isCycle(i)){
                return true;
            }
            else {
                noCycle.insert(i);
            }
        }
        visited.erase(curr);
        noCycle.insert(curr);
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto i:prerequisites){
            mp[i[1]].push_back(i[0]);
        }
        // DFS with backtracking to check if the graph contains cycle
        for(auto i:prerequisites){
            int curr = i[0];
            if(isCycle(curr)){
                return false;
            }
        }
        return true;
    }
};