#include <iostream>
#include <tuple>
using namespace std;

class TicTacToeGame {
public: 
    TicTacToeGame();
    virtual ~TicTacToeGame();
    void Play();

private:
    void initializeGrid();
    void displayGrid();
    tuple<int, int> findFirstUnoccupiedGridSquare();
    tuple<int, int> promptForGridCoordinates();
    bool checkForDraw();
    bool checkForWin();

private:
    char** gameGrid = nullptr;
};

TicTacToeGame::TicTacToeGame() {
    gameGrid = new char*[3];
    for(int i = 0; i < 3; ++i) {
        gameGrid[i] = new char[3];
    }
    initializeGrid();
}

TicTacToeGame::~TicTacToeGame() {
    for(int i = 0; i < 3; ++i) {
        delete[] gameGrid[i];
    }
    delete[] gameGrid;
    gameGrid = nullptr;
}

int main() {
    TicTacToeGame* game = new TicTacToeGame();
    game->Play();
    delete game;
    return 0;
}

void TicTacToeGame::initializeGrid() {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            gameGrid[i][j] = '~';
        }
    }
}

void TicTacToeGame::displayGrid() {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            cout << gameGrid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void TicTacToeGame::Play() {
    bool win = false;
    bool draw = false;
    int row = 0;
    int column = 0;

    cout << "Tic Tac Toe" << endl;
    cout << endl;
    displayGrid();

    while(!win && !draw) {
        tie(row, column) = promptForGridCoordinates();
        gameGrid[row][column] = 'X';
        displayGrid();
        win = checkForWin();
        draw = checkForDraw();

        if (!win && !draw) {
            tie(row, column) = findFirstUnoccupiedGridSquare();
            gameGrid[row][column] = 'O';
            displayGrid();
            win = checkForWin();
            draw = checkForDraw();
        }

        if (draw && !win) {
            cout << "Draw!" << endl;
        }
    }

    cout << "Game over." << endl;
    return;
}

tuple<int, int> TicTacToeGame::promptForGridCoordinates() {
    int row = 0;
    int column = 0;
    cout << "Enter row number: " << endl;
    cin >> row;
    cout << "Enter column number: " << endl;
    cin >> column;

    // Adjust for 0-based indexing
    row -= 1;
    column -= 1;

    tuple<int, int> coordinates = make_tuple(row, column);
    return coordinates;
}

tuple<int, int> TicTacToeGame::findFirstUnoccupiedGridSquare() {
    int rowUnoccupied = -1;
    int columnUnoccupied = -1;
    bool found = false;

    for(int i = 0; (i < 3) && (!found); ++i) {
        for(int j = 0; (j < 3) && (!found); ++j) {
            if (gameGrid[i][j] == '~') {
                rowUnoccupied = i;
                columnUnoccupied = j;
                found = true;
            }
        }
    }

    tuple<int, int> unoccupiedCoordinates(rowUnoccupied, columnUnoccupied);
    return unoccupiedCoordinates;
}

bool TicTacToeGame::checkForDraw() {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if (gameGrid[i][j] != 'X' && gameGrid[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

bool TicTacToeGame::checkForWin() {
    bool win = false;

    for(int i = 0; i < 3; ++i) {
        if (gameGrid[i][0] != '~' && gameGrid[i][0] == gameGrid[i][1] && gameGrid[i][0] == gameGrid[i][2]) {
            win = true;
            cout << "WINNER: " << gameGrid[i][0] << "!" << endl;
        }
    }

    for(int j = 0; j < 3; ++j) {
        if (gameGrid[0][j] != '~' && gameGrid[0][j] == gameGrid[1][j] && gameGrid[0][j] == gameGrid[2][j]) {
            win = true;
            cout << "WINNER: " << gameGrid[0][j] << "!" << endl;
        }
    }

    if (gameGrid[0][0] != '~' && gameGrid[0][0] == gameGrid[1][1] && gameGrid[0][0] == gameGrid[2][2]) {
        win = true;
        cout << "WINNER: " << gameGrid[0][0] << "!" << endl;
    }

    if (gameGrid[0][2] != '~' && gameGrid[0][2] == gameGrid[1][1] && gameGrid[0][2] == gameGrid[2][0]) {
        win = true;
        cout << "WINNER: " << gameGrid[0][2] << "!" << endl;
    }

    return win;
}
