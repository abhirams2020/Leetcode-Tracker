class Solution {
public:
    // O(N) time complexity using unordered_map
    
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
        // map sorts string lexicographically
        unordered_map<string,int> mp;
        string ans;
        int maxCount = 0;
        
        for(int i=0;i<messages.size();i++){
            mp[senders[i]] += countWords(messages[i]);
        }
        
        for(auto i:mp){
            // i.first>ans checks for lexicograpgical order
            if(i.second>maxCount || (i.second==maxCount && i.first>ans)){
                maxCount = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
    
//     // O(NlogN) time complexity using map
    
//     int countWords(string s){
//         int count = 0;
//         for(auto ch:s){
//             if(ch==' '){
//                 count++;
//             }
//         }
//         return count+1;
//     }
    
//     string largestWordCount(vector<string>& messages, vector<string>& senders) {
//         // map sorts string lexicographically
//         map<string,int> mp;
//         string ans;
//         int maxCount = 0;
        
//         for(int i=0;i<messages.size();i++){
//             mp[senders[i]] += countWords(messages[i]);
//         }
        
//         for(auto i:mp){
//             if(i.second>=maxCount){
//                 maxCount = i.second;
//                 ans = i.first;
//             }
//         }
//         return ans;
//     }
};