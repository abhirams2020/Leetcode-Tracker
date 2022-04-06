class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        if(n==0){
            return tasks.size();
        }
        unordered_map<char,int> mp;
        int ans = 0;
        for(auto i:tasks){
            mp[i]++;
        }
        priority_queue<int> pq;
        for(auto i:mp){
            pq.push(i.second);
        }
        
        queue<pair<int,int>> q;
        
        while(!q.empty() || !pq.empty()){
            ans += 1;
            if(!pq.empty()){
                if(pq.top()-1 != 0)
                    q.push(make_pair(pq.top() - 1, ans+n));
                pq.pop();
            }
            if(q.front().second == ans){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return ans;
    }
};