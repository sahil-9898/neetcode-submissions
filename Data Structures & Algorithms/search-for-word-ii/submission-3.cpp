class TrieNode {
    TrieNode* children[26];
public:
    bool end;
    string endString;
    TrieNode() {
        for (int i=0; i<26; i++) {
            children[i] = nullptr;
        }
        end = false;
    }

    TrieNode* get(char c) {
        return children[c - 'a'];
    }

    void insert(char c) {
        children[c - 'a'] = new TrieNode();
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
                dfs(i, j, board, root);
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
            node->endString = word;
        }
        return root;
    }

    void dfs(int x, int y, vector<vector<char>> &arr, TrieNode* node) {
        int m = arr.size();
        int n = arr[0].size();
        if (x >= m || y >= n || x < 0 || y < 0 || visited[x][y]) {
            return;
        }

        char c = arr[x][y];
        node = node->get(c);
        if (node) {
            if (node->end) {
                s.insert(node->endString);
            }
            visited[x][y] = true;
            dfs(x + 1, y, arr, node);
            dfs(x, y + 1, arr, node);
            dfs(x - 1, y, arr, node);
            dfs(x, y - 1, arr, node);
            visited[x][y] = false;
        }
    }
};
