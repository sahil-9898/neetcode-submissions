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

class Solution {
    vector<vector<bool>> visited;
    unordered_set<string> s;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        TrieNode* root = populatePrefixTree(words);
        int m = board.size();
        int n = board[0].size();
        visited.assign(m, vector<bool>(n, false));
        for (int i=0; i<board.size(); i++) {
            for (int j = 0; j<board[0].size(); j++) {
                dfs(i, j, board, root, "");
            }
        }
        return vector<string>(s.begin(), s.end());
    }
private:
    TrieNode* populatePrefixTree(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string word: words) {
            TrieNode* node = root;
            for (char c: word) {
                if (!node->get(c)) {
                    node->insert(c);
                }
                node = node->get(c);
            }
            node->end = true;
        }
        return root;
    }

    void dfs(int x, int y, vector<vector<char>> &arr, TrieNode* node, string word) {
        int m = arr.size();
        int n = arr[0].size();
        if (x >= m || y >= n || x < 0 || y < 0 || visited[x][y]) return;

        char c = arr[x][y];
        node = node->get(c);
        if (!node) return;
        
        word+=c;
        if (node->end) s.insert(word);
        visited[x][y] = true;
        dfs(x + 1, y, arr, node, word);
        dfs(x, y + 1, arr, node, word);
        dfs(x - 1, y, arr, node, word);
        dfs(x, y - 1, arr, node, word);
        visited[x][y] = false;
    }
};
