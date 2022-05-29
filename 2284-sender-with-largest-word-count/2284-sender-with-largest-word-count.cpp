class Solution {
public:
    int countWords(string s){
        int count = 0;
        for(auto ch:s){
            if(ch==' '){
                count++;
            }
        }
        return count+1;
    }
    
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> mp;
        string ans;
        int maxCount = 0;
        
        for(int i=0;i<messages.size();i++){
            mp[senders[i]] += countWords(messages[i]);
        }
        
        for(auto i:mp){
            if(i.second>=maxCount){
                maxCount = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};