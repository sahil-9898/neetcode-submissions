class TrieNode {
    TrieNode* children[26];
public:
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

    vector<TrieNode*> getAll() {
        vector<TrieNode*> links;
        for (int i=0;i<26;i++) {
            if (children[i]) {
                links.push_back(children[i]);
            }
        }
        return links;
    }

    void insert(char c) {
        children[c - 'a'] = new TrieNode();
    }
};

class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return dfs(word, 0, root);
    }

private:
    bool dfs(string word, int index, TrieNode* root) {
        TrieNode* node = root;
        for (int i=index;i<word.size();i++) {
            char c = word[i];
            if (c != '.') {
                if (!node->get(c)) {
                    return false;
                }
                node = node->get(c);
            }
            else {
                vector<TrieNode*> links = node->getAll();
                for (auto link: links) {
                    if (dfs(word, i + 1, link)) {
                        return true;
                    }
                }
                return false;
            }
        }
        return node->end;
    }
};
