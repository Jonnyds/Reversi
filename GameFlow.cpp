/*
 * name: Jonathan Schwarz
 * ID: 203672910
 */

#include "GameFlow.h"
#include <cmath>


using namespace std;

GameFlow::GameFlow(const int &n) {
    playing_board = new Board(n);
    white = new PlayerType(O);
    black = new PlayerHuman(X);
    turn = X;
    no_more_moves = 0;
}

void GameFlow::init_game() {
    playing_board->init(white,black);
}

void GameFlow::play() {
    int i;
    Disc d;
    coordinates chose;

    vector<coordinates> possible_moves;

    while (!isGameOver()) {

        playing_board->print();
        cout << endl << "The white player has: " << white.get_disc_list().size() << " discs on board" << endl;
        cout << "The black player has: " << black.get_disc_list().size() << " discs on board \n" << endl;

        BoardLogic *moves;

        if (turn == white.get_symbol()) {
            moves = new BoardLogic(playing_board, white, black);
        } else {
            moves = new BoardLogic(playing_board, black, white);
        }

        possible_moves = moves->valid_moves(); // checks the valid moves.

        if (possible_moves.empty()) { // check if both players have no more moves then the game ends.

            no_more_moves++;
            switchTurn(true);

        } else {
            no_more_moves = 0;

            switch (turn) {
                case X:
                  chose = black.makeMove(moves);
                    d = Disc(turn, chose.x, chose.y);
                    playing_board->add_to_board(d, chose.x, chose.y);
                    black.add_disc(d);
                    break;
                case O:
                   chose = white.makeMove(moves);
                    d = Disc(turn, chose.x, chose.y);
                    playing_board->add_to_board(d, chose.x, chose.y);
                    white.add_disc(d);
                    break;
                case E:
                    break;
            }

            moves->flipping(chose.x, chose.y); //makes the move (changes discs on board).

            switchTurn(false);

        }

        delete moves;

    }

    //win massage.
    winMassege();
}

bool GameFlow::isGameOver() {

    int total_disc = static_cast<int>(white.get_disc_list().size() + black.get_disc_list().size());
    if (total_disc != pow(playing_board->get_size() - 1, 2) && (no_more_moves != 2)) {
        return false;
    }
    return true;
}

void GameFlow::winMassege() {
    if (white.get_disc_list().size() > black.get_disc_list().size()) {
        cout << "The white player is the winner";
    } else {
        if (white.get_disc_list().size() < black.get_disc_list().size()) {
            cout << "The black player is the winner";
        } else {
            cout << "It's a tie";
        }
    }
}

void GameFlow::switchTurn(bool no_moves) {
    // switch turn.
    if(no_moves) {
        cout << "No possible moves - switching turn" << endl;
    }
    switch (turn) {
        case X:
            turn = O;
            cout << "It's the white player's turn \n" << endl;
            break;
        case O:
            turn = X;
            if(no_moves) {

            }
            cout << "It's the black player's turn \n" << endl;
            break;
        case E:
            break;
    }
}

GameFlow::~GameFlow() {
    delete playing_board;
}

