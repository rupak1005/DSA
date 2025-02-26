class Solution      {
public  : 
    bool isSafe(vector<string> &board, int row, int col, int n) {
        // Check horizontal
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }

        // Check vertical
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check left diagonal (top-left to bottom-right)
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check right diagonal (top-right to bottom-left)
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isSafe(board, row, j, n)) {
                board[row][j] = 'Q';  // Place a queen
                nQueens(board, row + 1, n, ans);  // Recur to place queen in next row
                board[row][j] = '.';  // Backtrack and remove queen
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));  // Create an empty board
        vector<vector<string>> ans;
        nQueens(board, 0, n, ans);  // Start solving from the first row
        return ans;
    }
};
