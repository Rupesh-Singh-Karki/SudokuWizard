#include <iostream>
#include <vector>

using namespace std;

// Function to check if placing 'val' at position (row, col) is safe
bool isSafe(int row, int col, vector<vector<int>> &board, int val) {
    // Check if 'val' is already in the same row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == val) {
            return false;
        }
    }

    // Check if 'val' is already in the same column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == val) {
            return false;
        }
    }

    // Check if 'val' is already in the 3x3 sub-grid
    int startRow = 3 * (row / 3);
    int startCol = 3 * (col / 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == val) {
                return false;
            }
        }
    }

    return true;
}

// Recursive function to solve the Sudoku board
bool solve(vector<vector<int>> &board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            // Check if the current cell is empty
            if (board[row][col] == 0) {
                for (int val = 1; val <= 9; val++) {
                    // Try placing 'val' and check if it's safe
                    if (isSafe(row, col, board, val)) {
                        board[row][col] = val;

                        // Recursively try to solve the rest of the board
                        if (solve(board)) {
                            return true;
                        }

                        // If placing 'val' didn't lead to a solution, backtrack
                        board[row][col] = 0;
                    }
                }
                // If no number can be placed, return false
                return false;
            }
        }
    }

    // All cells are filled correctly
    return true;
}

// Function to solve the Sudoku puzzle
void solveSudoku(vector<vector<int>>& sudoku) {
    if (!solve(sudoku)) {
        cout << "No solution exists." << endl;
    }
}

// Function to print the Sudoku board
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Main function to handle user input and display the solution
int main() {
    vector<vector<int>> board(9, vector<int>(9));

    cout << "Enter the Sudoku board (9x9) with 0 for empty cells:" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    solveSudoku(board);

    cout << "Solved Sudoku board:" << endl;
    printBoard(board);

    return 0;
}
