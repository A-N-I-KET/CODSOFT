#include <iostream>
#include <vector>

// Function prototypes
void initializeBoard(std::vector<std::vector<char>>& board);
void displayBoard(const std::vector<std::vector<char>>& board);
bool makeMove(std::vector<std::vector<char>>& board, char player, int row, int col);
bool checkWin(const std::vector<std::vector<char>>& board, char player);
bool checkDraw(const std::vector<std::vector<char>>& board);
void switchPlayer(char& currentPlayer);

int main() {
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;
    char playAgain;

    do {
        std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));

        initializeBoard(board);

        do {
            displayBoard(board);

            int row, col;

            // Get player input
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;

            // Make a move and check for valid move
            if (makeMove(board, currentPlayer, row, col)) {
                // Check for win
                gameWon = checkWin(board, currentPlayer);

                // Check for draw
                gameDraw = checkDraw(board);

                // Switch to the other player
                switchPlayer(currentPlayer);
            } else {
                std::cout << "Invalid move. Try again.\n";
            }

        } while (!gameWon && !gameDraw);

        displayBoard(board);

        // Display result
        if (gameWon) {
            std::cout << "Player " << currentPlayer << " wins!\n";
        } else {
            std::cout << "It's a draw!\n";
        }

        // Ask if players want to play again
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

void initializeBoard(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) {
                std::cout << "|";
            }
        }
        std::cout << "\n";
        if (i < 2) {
            std::cout << "  -----\n";
        }
    }
}

bool makeMove(std::vector<std::vector<char>>& board, char player, int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    } else {
        return false;
    }
}

bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkDraw(const std::vector<std::vector<char>>& board) {
    // Check if the board is full (draw)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // There is an empty space, game is not a draw
            }
        }
    }

    return true; // All spaces are filled, game is a draw
}

void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
