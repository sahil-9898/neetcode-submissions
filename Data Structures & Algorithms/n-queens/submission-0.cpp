class Solution {
    set<int> col;
    set<int> posDiag;
    set<int> negDiag;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;

        vector<vector<string>> board(n, vector<string>(n, "."));
        
        backtrack(board, 0, res, n);
        return res;
    }

    void backtrack(vector<vector<string>> &board, int r, vector<vector<string>> &res, int n) {
        if (r == n) {
            vector<string> x;
            for (auto ar: board) {
                string s = "";
                for (auto c: ar) {
                    s+=c;
                }
                x.push_back(s);
            }
            res.push_back(x);
            return;
        }

        for (int c=0;c<n;c++) {
            if (col.contains(c) || posDiag.contains(r+c) || negDiag.contains(r-c)) {
                continue;
            }
            col.insert(c);
            posDiag.insert(r+c);
            negDiag.insert(r-c);
            board[r][c] = "Q";
            backtrack(board, r+1, res, n);
            col.erase(c);
            posDiag.erase(r+c);
            negDiag.erase(r-c);
            board[r][c] = ".";
        }
    }
};
