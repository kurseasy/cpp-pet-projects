#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';
        currentPlayer = 'X';
    }

    void printBoard() {
        cout << "-------------\n";
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " | ";
            }
            cout << "\n-------------\n";
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
            return false;
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        // Проверка строк и столбцов
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        // Проверка диагоналей
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;

        return false;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() {
        return currentPlayer;
    }
};

int main() {
    TicTacToe game;
    int row, col;
    int moves = 0;

    while (true) {
        game.printBoard();
        cout << "Ход игрока " << game.getCurrentPlayer() << " (строка и столбец 0-2): ";
        cin >> row >> col;

        if (!game.makeMove(row, col)) {
            cout << "Неверный ход, попробуйте снова.\n";
            continue;
        }

        moves++;
        if (game.checkWin()) {
            game.printBoard();
            cout << "Победитель: " << game.getCurrentPlayer() << endl;
            break;
        }

        if (moves == 9) {
            game.printBoard();
            cout << "Ничья!\n";
            break;
        }

        game.switchPlayer();
    }

    return 0;
}
