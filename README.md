# Algorithm Solutions

Collection of algorithm and data structure solutions in C++ for practice and learning purposes.  
This repository contains exercises from books, competitive programming platforms, and personal practice.

---

## Table of Contents
- [About](#about)
- [Languages](#languages)
- [Folder Structure](#folder-structure)
- [Problems Solved](#problems-solved)
  - [Skiena Exercises](#skiena-exercises)
  - [LeetCode](#leetcode)
  - [Codeforces](#codeforces)
  - [HackerRank](#hackerrank)
- [How to Run](#how-to-run)
- [Contributing](#contributing)
- [License](#license)

---

## About
This repository contains solutions to algorithm problems from various sources:

- Skiena's *The Algorithm Design Manual*
- LeetCode
- Codeforces
- HackerRank
- Personal exercises and practice

The goal is to have a well-organized collection of solutions for learning, reference, and interview preparation.

---

## Languages
- C++  
- Python

---

## Folder Structure
- `LeetCode/` : solutions to LeetCode problems  
- `Skiena/` : exercises from Skiena's book  
- `Codeforces/` : competitive programming contests  
- `HackerRank/` : problems from HackerRank  
- `README.md` : this file  

Each folder contains standalone C++ files named with problem IDs and titles where possible.

---

## Problems Solved
Examples:

- **LeetCode**
  - 1: Two Sum
  - 2: Add Two Numbers
  - 3: Longest Substring Without Repeating Characters

### Skiena Exercises

#### Interactive Tic-Tac-Toe (n × n board)
An interactive Tic-Tac-Toe game for an n × n board using **O(n) space** and **O(1) time per move**.  
This version ensures safe input and displays the board after each move.

- **File:** [`Skiena/interactive_tic_tac_toe.cpp`](Skiena/interactive_tic_tac_toe.cpp)
- **Usage:** Compile and run the standalone C++ program.
- **Features:**
  - Ensures input coordinates are within bounds.
  - Prevents moves on already occupied cells.
  - Displays the current board after each valid move.
  - Reports the winner or a draw.

**Example Run:**
Enter board size n: 3
Player 'O', enter your move (row and column): 0 0

Board state:
O . .
. . .
. . .

Player 'X', enter your move (row and column): 1 1

Board state:
O . .
. X .
. . .

Player 'O', enter your move (row and column): 0 1

Board state:
O O .
. X .
. . .

Player 'X', enter your move (row and column): 1 0

Board state:
O O .
X X .
. . .

Player 'O', enter your move (row and column): 0 2

Board state:
O O O
X X .
. . .

Player 'O' wins!


**Notes:**
- The first player is always 'O'.
- Rows and columns are 0-indexed.
- The game stops immediately when a player wins or if all cells are filled resulting in a draw.

- **Codeforces**
  - Contest 1234: Problem A, Problem B, Problem C

---

## How to Run
Each solution is a standalone C++ file. To compile and run:

```bash
g++ solution.cpp -o solution
./solution

