class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        int ans = 0;
        for(auto i:s){
            mp[i]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto i:mp){
            pq.push(make_pair(i.second, i.first));
        }

        string res;
        
        while(pq.size()>1){ // if pq.size()==1 we wont get top2
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();
            
            res += top1.second;
            res += top2.second;
            
            top1.first--;
            top2.first--;
            
            if(top1.first > 0){
                pq.push(make_pair(top1.first,top1.second));
            }
            if(top2.first > 0){
                pq.push(make_pair(top2.first,top2.second));
            }
        }
        if(!pq.empty()){
            if(pq.top().first > 1){ // impossible to add more than 1 element in 1 space
                return "";
            }
            else {
                res += pq.top().second;
            }
        }
        return res;
    }
};