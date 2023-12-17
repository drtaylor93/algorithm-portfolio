/*
Drevon Taylor
CS627 IP5
December 16, 2023
*/

/*
Part 2A: State Space
I would search the sudoku board by creating a 2D array that represents the
board holding the value in each space. I would then iterate through the
array and record the location of each empty square (denoted by a 0). 
I would then iterate over the list of empty spaces and begin the process of determining
filling out each row until the sudoku board is complete.

The state space is the configuration of the nine grids, in my case this is being held in the
variable startGame. Each vertex within the tree is the space itself with the child nodes being
the choices availible for the tree (numbers 1 - 9).
*/



/*
Part 2B: Traversal Time Complexity
If solved using a brute force method the worst case time complexity would
be O(n^(n^2)) which can be plugged in to be O(9^9^2) -> O(9^81). Based on the references provided for 
the rules of Sudoku, I am assuming that the board will always be 9 x 9, but if the size of the board
differs we can simply plug in the new dimensions of n. 
*/



/* Part 2C: Heuristic Search

Personally I would use a backtracking algorithm to try to reduce the 
search time. The first step of a backtracking algorithm for sudoku would
be to find an empty square on the board and place a number there. We then
need to determine if the that number is already present in the row of 9 squares
or the column. We'd then need to also determine if the number is already
within which ever 3x3 grouping the selected square belonged to. If it passed these
three initial tests then we can move on to the next open square and pick a number.
However, if any of the three previous conditions arent met then the algorithm would
remove the number selected and fill in a new number, repeating the process. 

The time complexity for the worst case using backtracking would be
O(n(sqrt)n). This can happen in the event you have to constantly check 
the board for a possible solution due to one of the previous three conditions not being met.

I have used this tactic in previous interviews where I was asked to navigate a character
through a 2D map that has a set number of paths, of which only one is valid while the other
paths lead to dead ends. As I would navigate the character, each turn was a pivot
point so that if a dead end was reached, the algorithm would recursively undo moves until
the character returned to the last pivot point and it would turn in the other direction.

While there are several data structures that can be used to implement this solution, I used
a stack. Each square and number selection is added to the stack until either the puzzle is
solved or there is no longer a valid path forward, in which case each move is popped off the
stack until a pivot point is found.
*/



/*
Part 2D: Psuedocode
Below is the brute force implementation of a sudoku game. 
*/

#include <iostream>
#include <vector>

using namespace std;

bool playGame(vector<vector<int>>& board);
bool findEmptyCell(const vector<vector<int>>& board, int& row, int& col);
bool checkSquare(const vector<vector<int>>& board, int row, int col, int num);

int main() {
    
    // Starter Sudoku board
    vector<vector<int>> startGame = {
        {7, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 2, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 6, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 9, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 8, 0, 0, 0, 6},
        {0, 6, 1, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 1, 0, 0, 8, 0, 0, 7, 9}
    };

    // If true is returned then the game is over 
    if (playGame(startGame)) {
        cout << "Congratualations, you've solved the puzzle:\n";
        for (const auto& row : startGame) {
            for (int num : row) {
                cout << num << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Game Over.\n" << std::endl;
    }

    return 0;
}


bool playGame(vector<vector<int>>& board) {
    int row, col;

    if (!findEmptyCell(board, row, col)) {
        return true; 
    }

    // Try placing numbers from 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (checkSquare(board, row, col, num)) {
            // Place the number if it's safe
            board[row][col] = num;

            if (playGame(board)) {
                return true;  // Solution found
            }

            board[row][col] = 0;
        }
    }

    return false;
}

/*

getEmptySquare goes through the board from location [0,0] until the end looking for
empty squares which is marked by a value of zero.

Parameters:
board vector<int>: 2D array representing the current state of the Sudoku game
row int&: row number
col int&: column number
*/

bool getEmptySquare(const vector<vector<int>>& board, int& row, int& col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                return true;  
            }
        }
    }
    return false;  
}

/*
checkSquare checks for each game condition to ensure a rule was not broken.

Parameters:
board vector<int>: 2D array representing the current state of the Sudoku game
row int&: row number
col int&: column number
*/
bool checkSquare(const vector<vector<int>>& board, int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num || board[row - row % 3 + i / 3][col - col % 3 + i % 3] == num) {
            return false;
        }
    }
    return true;
}

