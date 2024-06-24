#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];
char Player;

void initialise() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void boardDisplay() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < SIZE - 1) {
            cout << "-----" << endl;
        }
    }
}

bool validMove(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ';
}

void makeMove(int row, int col) {
    if (validMove(row, col)) {
        board[row][col] = Player;
    } else {
        cout << "Invalid move. Try again.\n";
    }
}

bool checkingWin() {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == Player && board[i][1] == Player && board[i][2] == Player) ||
            (board[0][i] == Player && board[1][i] == Player && board[2][i] == Player)) {
            return true;
        }
    }
    if ((board[0][0] == Player && board[1][1] == Player && board[2][2] == Player) ||
        (board[0][2] == Player && board[1][1] == Player && board[2][0] == Player)) {
        return true;
    }
    return false;
}

bool Draw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void changePlayer() {
    Player = (Player == 'X') ? 'O' : 'X';
}

void gamePlay() {
    initialise();
    Player = 'X';
    bool gameWon = false;

    while (!gameWon && !Draw()) {
        boardDisplay();
        int row, col;
        cout << "Player " << Player << ", Enter your move (row and column): ";
        cin >> row >> col;

        if (validMove(row, col)) {
            makeMove(row, col);
            gameWon = checkingWin();
            if (!gameWon) {
                changePlayer();
            }
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }

    boardDisplay();
    if (gameWon) {
        cout << "Player " << Player << " wins!\n";
    } else {
        cout << "The game is a draw!\n";
    }
}

int main() {
    char PlayAgain;
    do {
        gamePlay();
        cout << "Play again? (Y/N): ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
    return 0;
}
