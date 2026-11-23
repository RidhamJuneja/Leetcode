class TrieNode{
    public:
    bool endofword;
    TrieNode* child[26];
    TrieNode()
    {
        endofword=false;
        for(int i=0; i<26; i++)
        {
            child[i] = nullptr;
        }
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word)
        {
            int index = c-'a';
            if(!node->child[index])
            {
                node->child[index] = new TrieNode();
            }
            node = node -> child[index];
        }
        node -> endofword = true;
        return;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char c : word)
        {
            int index = c-'a';
            if(!node -> child[index])
            return false;
            
            node = node->child[index];
        }
        if(node -> endofword == true)
        return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix)
        {
            int index = c-'a';
            if(!node -> child[index])
            return false;

            node = node->child[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */