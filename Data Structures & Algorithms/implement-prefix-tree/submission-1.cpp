class TrieNode {
    unordered_map<char, TrieNode*> children;
public:
    bool end = false;

    TrieNode* get(char c) {
        if (children.contains(c)) {
            return children[c];
        }
        return nullptr;
    }

    void insert(char c) {
        children[c] = new TrieNode();
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
            if (!node->get(c)) {
                node->insert(c);
            }
            node = node->get(c);
        }
        node->end = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c: word) {
            if (!node->get(c)) {
                return false;
            }
            node = node->get(c);
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c: prefix) {
            if (!node->get(c)) {
                return false;
            }
            node = node->get(c);
        }
        return true;
    }
};
