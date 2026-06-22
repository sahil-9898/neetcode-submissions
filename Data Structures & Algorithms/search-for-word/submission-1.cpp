class Solution {
    vector<vector<bool>> visited;
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        visited.assign(m, vector<bool>(n, false));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (bfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool bfs(vector<vector<char>>& board, string word, int x, int y, int i) {
        int m = board.size();
        int n = board[0].size();

        if (i == word.length()) {
            return true;
        }

        if (x >= m || y >= n || x < 0 || y < 0 || visited[x][y] || board[x][y] != word[i]) {
            return false;
        }
        visited[x][y] = true;
        bool a = bfs(board, word, x+1, y, i + 1);
        bool b = bfs(board, word, x-1, y, i + 1);
        bool cc = bfs(board, word, x, y+1, i + 1);
        bool d = bfs(board, word, x, y-1, i + 1);
        visited[x][y] = false;
        return a || b || cc || d;
    }
};
