// class Solution {
// public:
//     // USING BACKTRACKING + HASHMAP
//     bool dfs(vector<vector<char>>& board, int i, int j, string &word, int index) {
//         if(index == word.size()){
//             return true;
//         }
//         if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='$' || board[i][j]!=word[index]){
//             return false;
//         }
//         bool ans;
//         char temp = board[i][j];
//         board[i][j] = '$';
//         ans =   dfs(board,i+1,j,word,index+1) ||
//                 dfs(board,i-1,j,word,index+1) ||
//                 dfs(board,i,j+1,word,index+1) ||
//                 dfs(board,i,j-1,word,index+1) ;
//         board[i][j] = temp;
//         return ans;
//     }
    
//     // map to store starting points of a character
//     unordered_map<char, vector<pair<int,int>> > charStart;
    
//     void searchWord(vector<vector<char>>& board, string word, vector<string> &res) {
//         for(auto point:charStart[word[0]]){
//             if(dfs(board,point.first,point.second,word,0)==true){
//                 res.push_back(word);
//                 return;
//             }
//         }
//     }
    
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         vector<string> res;
//         // add starting points of all characters present in board
//         for(int i=0;i<board.size();i++){
//             for(int j=0;j<board[0].size();j++){
//                 charStart[board[i][j]].push_back({i,j});
//             }
//         }
//         // search every word in grid
//         for(auto s:words){
//             searchWord(board,s,res);
//         }
//         return res;
//     }
// };

// USING TRIE (PREFIX TREE)

// efficient to check if a prefix exist in trie
// need to traverse a starting point only once
class TrieNode {
public:
    bool isEnd;
    string word; // store the word  from root to a node
    vector<TrieNode*> children;
    
    TrieNode() {
        isEnd = false;
        word = "";
        children.resize(26,NULL);
    }
    
    void insert(string &word) {
        TrieNode* curr = this;
        for(auto c:word){
            if(curr->children[c-'a'] == NULL){
                curr->children[c-'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
        }
        curr->isEnd = true;
        curr->word = word;
    }
};

class Solution {
public:
    vector<string> res;
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* curr) {
        // if prefix not exist in trie, return
        if(curr == NULL){
            return;
        }
        
        // if curr is ending node of a word, add word to result vector
        if(curr->isEnd){
            res.push_back(curr->word);
            curr->isEnd = false; // make curr->word="" after inserting in res to avoid duplication
        }
        
        // if index out of range or board[i][j] was visited earlier, return
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='$'){
            return;
        }
        
        curr = curr->children[board[i][j]-'a'];
        
        // backtracking
        char temp = board[i][j];
        board[i][j] = '$';
        
        dfs(board,i+1,j,curr);
        dfs(board,i-1,j,curr);
        dfs(board,i,j+1,curr);
        dfs(board,i,j-1,curr);
        
        board[i][j] = temp;
    }
    
    // function to build trie using given words
    TrieNode* buildTrie(vector<string> &words){
        TrieNode* root = new TrieNode();
        for(int i=0;i<words.size();i++){
            root->insert(words[i]);
        }
        return root;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        
        // search every word in grid
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(root->children[board[i][j]-'a'] != NULL){
                    dfs(board,i,j,root);
                }
            }
        }
        
        return res;
    } 
};