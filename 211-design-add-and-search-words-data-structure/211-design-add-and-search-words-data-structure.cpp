class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary(): root(new TrieNode()) {}
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        addWord(word,0,root);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word,0,root);
    }
private:
    struct TrieNode {
        TrieNode():child(vector<TrieNode*>(26,NULL)), isLeaf(false) {}
        vector<TrieNode*> child;
        bool isLeaf;
    };
    
    TrieNode* root;
    
    void addWord(const string& word, size_t i, TrieNode* cur) {
        if(i==word.length()) return;
        size_t j = word[i] - 'a';
        if(!cur->child[j]) cur->child[j] = new TrieNode();
        if(i==word.length()-1) cur->child[j]->isLeaf=true;
        addWord(word,i+1,cur->child[j]);
    }
    
    bool search(const string& word, size_t i, TrieNode* cur) const {
        if(i==word.length()) return false;
        
        if(word[i]!='.') {
            size_t j = word[i] - 'a';
            if(!cur->child[j]) return false;
            if(i==word.length()-1 && cur->child[j]->isLeaf) return true;
            return search(word,i+1,cur->child[j]);
        }
        else {
            for(TrieNode* node:cur->child) {
                if(node) {
                    if(i==word.length()-1 && node->isLeaf) return true;
                    if(search(word,i+1,node)) return true;
                }
            }
            return false;
        }
    }
    
};

// class TrieNode {
// public:
//     bool is_word;
//     unordered_map<char,TrieNode*> children;
//     TrieNode() {
//         is_word = false;
//     }
// };

// class WordDictionary {
// private:
//     TrieNode* root;
    
// public:
//     /** Initialize your data structure here. */
//     WordDictionary() {
//         root = new TrieNode();
//     }
    
//     /** Adds a word into the data structure. */
//     void addWord(string word) {
//         TrieNode* curr = root;
//         for(auto c:word){
//             if(curr->children.count(c) == 0){
//                 curr->children[c] = new TrieNode();
//             }
//             curr = curr->children[c];
//         }
//         curr->is_word = true;
//     }
    
//     /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
//     bool search(string word) {
//         return searchTrie(word,0, root);
//     }
    
//     // function to check if word from index i is present in trie starting at curr
//     bool searchTrie(string &word, int index, TrieNode* curr) {
//         for (int i = index; i<word.length() ; i++) {
//             if (word[i] == '.'){
//                 // if word[i]=='.', do dfs on all the children with word.substr(i+1)
//                 // if any dfs returns true, there exist a word. Return true
//                 for (auto node:curr->children) {
//                     if (searchTrie(word, i + 1, node.second)) {
//                         return true;
//                     }
//                 }
//                 return false;
//             }
            
//             if(curr->children.count(word[i]) == 0){
//                 return false;
//             }
//             curr = curr->children[word[i]];
//         }
//         return curr->is_word;
//     }
// };

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */