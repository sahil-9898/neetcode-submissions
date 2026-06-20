class TrieNode {
public:
    TrieNode* children[26];
    bool end;

    TrieNode() {
        for (int i=0;i<26;i++) {
            children[i] = nullptr;
        }
        end = false;
    }

    TrieNode* get(char c) {
        return children[c - 'a'];
    }

    void insert(char c) {
        TrieNode* node = new TrieNode();
        children[c - 'a'] = node;
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
