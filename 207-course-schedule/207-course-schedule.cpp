class Solution {
public:
    unordered_map<int,vector<int>> mp;
    unordered_set<int> visited;
    unordered_set<int> noCycle;
    
    bool isCycle(int curr){
        if(noCycle.count(curr)){
            return false;
        }
        if(visited.count(curr)){
            return true;
        }
        visited.insert(curr);
        for(auto i:mp[curr]){
            if(isCycle(i)){
                return true;
            }
            else {
                noCycle.insert(i);
            }
        }
        // visited.erase(curr);
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto i:prerequisites){
            mp[i[1]].push_back(i[0]);
        }
        for(auto i:prerequisites){
            int curr = i[0];
            if(isCycle(curr)){
                return false;
            }
            visited.clear();
            noCycle.insert(curr);
        }
        return true;
    }
};