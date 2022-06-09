// // USING DICTIONARY TO STORE NEXT CHARACTERS AND ITS NODE
// class TrieNode {
// public:
//     bool is_word;
//     // map stores next node of current characters
//     unordered_map<int,TrieNode*> children;
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
//             if(curr->children.count(c-'a') == 0){
//                 curr->children[c-'a'] = new TrieNode();
//             }
//             curr = curr->children[c-'a'];
//         }
//         curr->is_word = true;
//     }
    
//     /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
//     bool search(string word) {
//         return searchTrie(word,0,root);
//     }
    
//     // function to check if word from index i is present in trie starting at curr
//     bool searchTrie(string &word, int index, TrieNode* curr) {
//         for (int i = index; i<word.length() ; i++) {
//             if (word[i] == '.'){
//                 for (auto node:curr->children) {
//                     if (searchTrie(word, i+1, node.second)) {
//                         return true;
//                     }
//                 }
//                 return false;
//             }
//             if(curr->children.count(word[i]-'a') == 0){
//                 return false;
//             }
//             curr = curr->children[word[i]-'a'];
//         }
//         return curr->is_word;
//     }
// };

// USING VECTOR TO STORE NEXT NODES
class TrieNode {
public:
    bool is_word;
    TrieNode* children[26];
    TrieNode() {
        is_word = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
private:
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* curr = root;
        for(auto i:word){
            if(curr->children[i-'a'] == NULL){
                curr->children[i-'a'] = new TrieNode();
            }
            curr = curr->children[i-'a'];
        }
        curr->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchTrie(word,0, root);
    }
    
    // function to check if word from index i is present in trie starting at curr
    bool searchTrie(string &word, int index, TrieNode* curr) {
        for (int i = index; i<word.length() ; i++) {
            if (word[i] == '.'){
                // if word[i]=='.', do dfs on all the children with word.substr(i+1)
                // if any dfs returns true, there exist a word. Return true
                for (auto node:curr->children) {
                    if (node!=NULL && searchTrie(word, i + 1, node)) {
                        return true;
                    }
                }
                return false;
            }
            
            if(curr->children[word[i]-'a'] == NULL){
                return false;
            }
            curr = curr->children[word[i]-'a'];
        }
        return curr->is_word;
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */