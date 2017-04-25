/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */

/*For KK: This is a general implementation for word_search_II.
  You may not need a size 26 children vector for this problem. Instead, you can declare a variable "char letter" to store the node's value. And push_back a new node whenever needed. In this case, you have to implement a "find child" function for TrieNode because the index of children is no longer 'a'-'z' ordered.
*/
class TrieNode {
public:
    bool is_end;
    vector<TrieNode*> children;
    // Initialize your data structure here.
    TrieNode(): is_end(false) {
        children.resize(26);
        fill(children.begin(), children.end(), nullptr);
    }
    ~TrieNode(){
        for (int i=0; i<26; i++) if (children[i]) delete children[i];
    }
};

class Trie {
public:
    Trie() {root = new TrieNode();}
    ~Trie() {delete root;}
    
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur = root;
        for (int i=0; i<word.length(); i++){
            if (cur->children[word[i]-'a'] == nullptr){
                cur->children[word[i]-'a'] = new TrieNode();
            }
            cur = cur->children[word[i]-'a'];
        }
        cur->is_end = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
        for (int i=0; i<word.length(); i++){
            if (cur->children[word[i]-'a'] == nullptr) return false;
            cur = cur->children[word[i]-'a'];
        }
        return cur->is_end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (int i=0; i<prefix.length(); i++){
            if (cur->children[prefix[i]-'a'] == nullptr) return false;
            cur = cur->children[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};
