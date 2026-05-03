class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0};
        int col[9] = {0};
        int box[9] = {0};

        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '1';
                int boxIndex = (i/3) * 3 + (j/3);
                if ((row[i] & (1 << val)) || (col[j] & (1 << val)) || (box[boxIndex] & (1 << val))){
                    return false;
                }
                row[i] |= 1 << val;
                col[j] |= 1 << val;
                box[boxIndex] |= 1 << val;
            }
        }
        return true;
    }
};
