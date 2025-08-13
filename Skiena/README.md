#### Interactive Tic-Tac-Toe (n × n board)
An interactive Tic-Tac-Toe game for an n × n board using **O(n) space** and **O(1) time per move**.  
This version ensures safe input and displays the board after each move.

- **File:** [`interactive_tic_tac_toe.cpp`](interactive_tic_tac_toe.cpp)
- **Usage:** Compile and run the standalone C++ program.
- **Features:**
  - Ensures input coordinates are within bounds.
  - Prevents moves on already occupied cells.
  - Displays the current board after each valid move.
  - Reports the winner or a draw.

**Notes:**
- The first player is always 'O'.
- Rows and columns are 0-indexed.
- The game stops immediately when a player wins or if all cells are filled resulting in a draw.
