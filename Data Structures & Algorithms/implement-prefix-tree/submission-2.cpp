class TrieNode {
    unordered_map<char, TrieNode*> children;

    public:
        bool end = false;
        void put(char c) {
            if (children.contains(c)) {
                return;
            }
            children[c] = new TrieNode();
        }

        TrieNode* get(char c) {
            if (children.contains(c)) {
                return children[c];
            }
            return nullptr;
        }
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c: word) {
            node->put(c);
            node = node->get(c);
        }
        node->end = true;
    }
    
    bool search(string word) {
        TrieNode* node =  root;
        for (char c: word) {
            TrieNode* next = node->get(c);
            if (!next) return false;
            node = next;
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c: prefix) {
            TrieNode* next = node->get(c);
            if (!next) return false;
            node = next;
        }
        return true;
    }
};
