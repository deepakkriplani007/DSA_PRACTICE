class Solution {
public:
    bool fillsudoku(vector<vector<char>>& board, vector<vector<bool>>& row,
                    vector<vector<bool>>& col, vector<vector<bool>>& box) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    int ind = (i / 3) * 3 + j / 3;
                    for (int k = 0; k < 9; k++) {
                        if (!row[i][k] && !col[j][k] && !box[ind][k]) {
                            board[i][j] = '1' + k;
                            row[i][k] = col[j][k] = box[ind][k] = true;

                            if (fillsudoku(board, row, col, box))
                                return true;

                            // backtrack
                            board[i][j] = '.';
                            row[i][k] = col[j][k] = box[ind][k] = false;
                        }
                    }
                    return false; // if no number fits
                }
            }
        }
        return true; 
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int ind = (i / 3) * 3 + j / 3;
                    row[i][num] = col[j][num] = box[ind][num] = true;
                }
            }
        }

        fillsudoku(board, row, col, box);
    }
};
