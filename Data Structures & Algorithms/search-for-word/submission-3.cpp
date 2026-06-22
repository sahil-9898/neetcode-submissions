class Solution {
    vector<vector<bool>> visited;
    int rows;
    int cols;
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        visited.assign(rows, vector<bool>(cols, false));
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (bfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool bfs(vector<vector<char>>& board, string word, int x, int y, int i) {
        if (x >= rows || y >= cols || x < 0 || y < 0 || visited[x][y] || board[x][y] != word[i]) {
            return false;
        }

        if (i == word.length() - 1) return true;

        visited[x][y] = true;
        bool a = bfs(board, word, x+1, y, i + 1);
        bool b = bfs(board, word, x-1, y, i + 1);
        bool cc = bfs(board, word, x, y+1, i + 1);
        bool d = bfs(board, word, x, y-1, i + 1);
        visited[x][y] = false;
        return a || b || cc || d;
    }
};
