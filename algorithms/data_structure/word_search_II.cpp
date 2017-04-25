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

    TrieNode* root;
};

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        // write your code here
        vector<string> res;
        if (board.size()==0 || words.size()==0) return res;
        
        Trie *word_trie = new Trie();
        for (int i=0; i<words.size(); i++){
            word_trie->insert(words[i]);
        }
        
        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[0].size(); j++){
                string str;
                helper_DFS(board, word_trie->root, i, j, res, str);
            }
        }
        return res;
    }

private:
    void helper_DFS(vector<vector<char> > &board, TrieNode *cur, int i, int j, vector<string> &res, string &str){
        char c = board[i][j];
        if (c=='$' || cur->children[c-'a']==nullptr) return;
        cur = cur->children[c-'a'];
        str += c;
        if (cur->is_end){
            res.push_back(str);
            cur->is_end = false;
        }
        
        board[i][j] = '$';
        if (i>0) helper_DFS(board,cur,i-1,j,res,str);
        if (j>0) helper_DFS(board,cur,i,j-1,res,str);
        if (i<board.size()-1)  helper_DFS(board,cur,i+1,j,res,str);
        if (j<board[0].size()-1) helper_DFS(board,cur,i,j+1,res,str);
        board[i][j] = c;
        str.pop_back();
    }
};
