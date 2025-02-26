#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col, char digit) {
    // Horizontal check
    for (int j = 0; j < 9; j++) {
        if (board[row][j] == digit) {
            return false;
        }
    }

    // Vertical check
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == digit) {
            return false;
        }
    }

    // 3x3 Grid check
    int stRow = (row / 3) * 3;
    int stCol = (col / 3) * 3;
    for (int i = stRow; i < stRow + 3; i++) {
        for (int j = stCol; j < stCol + 3; j++) {
            if (board[i][j] == digit) {
                return false;
            }
        }
    }

    return true;
}

bool helper(vector<vector<char>>& board, int row, int col) {
    // Base case: if we reach the 9th row, the board is complete
    if (row == 9) {
        return true;
    }

    // Move to the next column
    int nextRow = row;
    int nextCol = col + 1;
    if (nextCol == 9) {
        nextCol = 0;
        nextRow = row + 1;
    }

    // Skip filled cells
    if (board[row][col] != '.') {
        return helper(board, nextRow, nextCol);
    }

    // Try placing digits '1' to '9'
    for (char digit = '1'; digit <= '9'; digit++) {
        if (isSafe(board, row, col, digit)) {
            board[row][col] = digit;  // Place the digit

            // Recursively attempt to fill the next cells
            if (helper(board, nextRow, nextCol)) {
                return true;  // If the next cell can be filled, return true
            }

            // Backtrack: if placing digit didn't work, reset the cell
            board[row][col] = '.';
        }
    }

    return false;  // If no digits work, return false
}

void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void solveSudoku(vector<vector<char>>& board) {
    helper(board, 0, 0);  // Start solving from the first cell
}

int main() {
    // Example Sudoku board (with empty cells represented by '.')
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    // Solve the Sudoku
    solveSudoku(board);

    // Print the solved Sudoku
    cout << "Solved Sudoku Board:" << endl;
    printBoard(board);

    return 0;
}