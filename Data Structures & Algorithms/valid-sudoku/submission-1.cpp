class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> row;
        unordered_map<int, unordered_set<char>> column;
        unordered_map<int, unordered_set<char>> box;
        
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                int boxIndex = (i/3) * 3 + (j / 3);
                if (row[i].find(c) != row[i].end() || column[j].find(c) != column[j].end() || box[boxIndex].find(c) != box[boxIndex].end()) {
                    return false;
                }
                row[i].insert(c);
                column[j].insert(c);
                box[boxIndex].insert(c);
            }
        }
        return true;
    }
};
