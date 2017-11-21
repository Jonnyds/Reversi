/*
 * name: Jonathan Schwarz
 * ID: 203672910
 */

#include "Board.h"

Board::Board(const int &n) : size(n+1){
    board = new Disc*[size]; // Creating a one dimensional pointers array (of type disc).
    for (int i = 0; i < size; ++i) {
        board[i] = new Disc[size]; // Creating a second dimension for each cell in the first dimension array
    }

    Disc empty(E);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = empty; // Adds an empty disc object to all the cells in the board.
        }
    }
}
void Board::print() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == 0 && j > 0) {
                cout << j << '|';
            } else {
                if (j == 0 && i > 0) {
                    cout << i << '|';
                } else {
                    cout << (char) board[i][j].get_sym() << '|';
                }
            }

        }
        cout << endl;
        for (int j = 0; j < size; ++j) {
            cout << "- ";
        }
        cout << endl;
    }
}

int Board::get_size() {
    return size;
}

Disc **Board::get_board() {
    return board;
}

void Board::init( Player &white, Player &black) {
    /**
     * Creating the first four discs.
     */
    Disc odisc44(O,size / 2,size / 2);
    Disc xdisc45(X,size / 2,size / 2 + 1);
    Disc odisc55(O,size / 2 + 1,size / 2 + 1);
    Disc xdisc54(X,size / 2 + 1,size / 2);
    /**
     * Adding the first four discs to the board.
     */
    board[size / 2][size / 2] = odisc44;
    board[size / 2][size / 2 + 1] = xdisc45;
    board[size / 2 + 1][size / 2 + 1] = odisc55;
    board[size / 2 + 1][size / 2] = xdisc54;
    /**
     * adding the first four discs to the player's lists.
     */
    white.add_disc(odisc44);
    white.add_disc(odisc55);
    black.add_disc(xdisc45);
    black.add_disc(xdisc54);
}

void Board::add_to_board(const Disc &d, const int &i, const int &j) {
    board[i][j] = d;
}

Board::~Board() {

    for(int i=0; i <size; i++) {
        delete[] board[i];
    }
    delete [] board;

};

Board::Board() {} // Empty constructor to create an empty object of that type (not initialized).


