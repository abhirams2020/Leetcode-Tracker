class TrieNode {
public:
    bool is_word;
    vector<TrieNode*> children;
    
    TrieNode() {
        is_word = false;
        children.resize(26,NULL);
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* curr = root;
        // in case of inserting apple after app, no need to change is_word value at p
        // each is_word=true represents a word in the trie
        for(auto i:word){
            if(curr->children[i-'a'] == NULL){
                curr->children[i-'a'] = new TrieNode();
            }
            curr = curr->children[i-'a'];
        }
        // after all letters inserted, change is_word to true to mark end of word
        curr->is_word = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* curr = root;
        int i = 0;
        while(i<word.length()){
            if(curr->children[word[i]-'a'] == NULL){
                return false;
            }
            curr = curr->children[word[i]-'a'];
            i++;
        }
        // if there is more letters present, it will have is_word = false. If end of word, then is_word = true
        return curr->is_word;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int i = 0;
        while(i<prefix.length()){
            if(curr->children[prefix[i]-'a'] == NULL){
                return false;
            }
            curr = curr->children[prefix[i]-'a'];
            i++;
        }
        // if all letters are found, it means prefix exist
        return true;        
    }
    
    // ADDITIONAL COMPONENT -- DESTRUCTOR TO FREE MEMORY
    ~Trie() {
        clear(root);
    }
    
    void clear(TrieNode* root){
        for(auto node:root->children){
            if(node!=NULL){
                clear(node);
            }
        }
        
        delete root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */