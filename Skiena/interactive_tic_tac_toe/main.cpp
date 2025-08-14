#include <iostream>
#include <vector>
using namespace std;

/*
Interactive Tic-Tac-Toe on an n × n board with safe input.
Two players take turns placing 'O' and 'X' on the board.
A player wins if they place n consecutive marks in a row, column, or diagonal.

This implementation uses O(n) space, reports in O(1) time whether
the last move won the game, and shows the board after each move.
*/

// Function to print the current board
void printBoard(const vector<vector<char>> &board) {
    int n = board.size();
    cout << "\nBoard state:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter board size n: ";
    cin >> n;

    vector<int> rowCount(n, 0);     // Track marks per row
    vector<int> colCount(n, 0);     // Track marks per column
    int mainDiag = 0;               // Count for main diagonal
    int antiDiag = 0;               // Count for anti-diagonal
    vector<vector<char>> board(n, vector<char>(n, '.')); // Board state

    char currentPlayer;

    for (int move = 0; move < n * n; ) {
        int i, j;
        cout << "Player " << ((move % 2 == 0) ? "'O'" : "'X'") << ", enter your move (row and column): ";
        cin >> i >> j;

        // Validate input
        if (i < 0 || i >= n || j < 0 || j >= n) {
            cout << "Invalid move! Coordinates must be between 0 and " << n-1 << ". Try again.\n";
            continue;
        }
        if (board[i][j] != '.') {
            cout << "Cell already occupied! Try again.\n";
            continue;
        }

        // Make the move
        currentPlayer = (move % 2 == 0) ? 'O' : 'X';
        board[i][j] = currentPlayer;

        // Update counts
        int delta = (currentPlayer == 'O') ? 1 : -1;
        rowCount[i] += delta;
        colCount[j] += delta;
        if (i == j) mainDiag += delta;
        if (i + j == n - 1) antiDiag += delta;

        // Print current board
        printBoard(board);

        // Check for win
        if (rowCount[i] == n || colCount[j] == n || mainDiag == n || antiDiag == n) {
            cout << "Player 'O' wins!\n";
            break;
        } else if (rowCount[i] == -n || colCount[j] == -n || mainDiag == -n || antiDiag == -n) {
            cout << "Player 'X' wins!\n";
            break;
        }

        move++; // increment move only after valid input

        // Check for draw
        if (move == n * n) {
            cout << "Draw!\n";
        }
    }

    return 0;
}
