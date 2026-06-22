class Solution {
    vector<vector<bool>> visited;
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        visited.assign(m, vector<bool>(n, false));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (bfs(board, word, i, j, "")) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool bfs(vector<vector<char>>& board, string word, int x, int y, string curr) {
        int m = board.size();
        int n = board[0].size();

        if (curr.length() == word.length() || x >= m || y >= n || x < 0 || y < 0 || visited[x][y]) {
            return false;
        }

        char c = board[x][y];
        curr += c;
        visited[x][y] = true;
        if (curr == word) {
            return true;
        }
        bool a = bfs(board, word, x+1, y, curr);
        bool b = bfs(board, word, x-1, y, curr);
        bool cc = bfs(board, word, x, y+1, curr);
        bool d = bfs(board, word, x, y-1, curr);
        visited[x][y] = false;
        curr.pop_back();
        return a || b || cc || d;
    }
};
