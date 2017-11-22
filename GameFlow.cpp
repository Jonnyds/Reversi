/*
 * name: Jonathan Schwarz
 * ID: 203672910
 */

#include "GameFlow.h"
#include "BoardLogic.h"
#include <cmath>
#include <limits>

using namespace std;

GameFlow::GameFlow(const int &n) {
    playing_board = new Board(n);
    white = Player(O);
    black = Player(X);
    turn = X;
    no_more_moves = 0;
}

void GameFlow::init_game() {
    playing_board->init(white,black);
}

void GameFlow::play() {
    int i;
    int x = 0, y = 0;
    bool move_found;

    vector<coordinates> possible_moves;

    while (!isGameOver()) {
        move_found = false;

        playing_board->print();
        cout << endl << "The white player has: " << white.get_disc_list().size() << " discs on board" << endl;
        cout << "The black player has: " << black.get_disc_list().size() << " discs on board \n" << endl;

        BoardLogic *moves;

        if (turn == white.get_symbol()) {
            moves = new BoardLogic(playing_board, white, black, turn);
        } else {
            moves = new BoardLogic(playing_board, black, white, turn);
        }

        possible_moves = moves->valid_moves(); // checks the valid moves.

        if (possible_moves.empty()) { // check if both players have no more moves then the game ends.
            no_more_moves++;
            switch (turn) {
                case X:
                    turn = O;
                    cout << "No possible moves - switching turn" << endl;
                    cout << "It's the white player's turn \n" << endl;
                    break;
                case O:
                    cout << "No possible moves - switching turn" << endl;
                    cout << "It's the black player's turn \n" << endl;
                    turn = X;
                    break;
                case E:
                    break;
            }

        } else {
            cout << "possible moves:";
            moves->print_vec();
            no_more_moves = 0;

            while (!move_found) { // This part checks of the input is valid.

                cout << "please enter the coordinates of the move you would like to make:";
                cin >> x;
                cin >> y;

                for (int move = 0; move < possible_moves.size(); move++) {
                    if (x == possible_moves[move].x && y == possible_moves[move].y) {
                        move_found = true;
                        cout << "Your move is (" << x << ',' << y <<')' <<endl << endl;
                    }
                }
                if(!move_found) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Please enter numbers only! \n";
                }
            }

            // adds the chosen location disc to board
            Disc d(turn, x, y);
            playing_board->add_to_board(d, x, y);

            switch (turn) {
                case X:
                    black.add_disc(d);
                    break;
                case O:
                    white.add_disc(d);
                    break;
                case E:
                    break;
            }


                moves->make_move(x, y); //makes the move (changes discs on board).

            // switch turn.
            switch (turn) {
                case X:
                    turn = O;
                    cout << "It's the white player's turn \n" << endl;
                    break;
                case O:
                    turn = X;
                    cout << "It's the black player's turn \n" << endl;
                    break;
                case E:
                    break;
            }

        }

        delete moves;

    }

    //win massage.
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

bool GameFlow::isGameOver() {

    int total_disc = static_cast<int>(white.get_disc_list().size() + black.get_disc_list().size());
    if (total_disc != pow(playing_board->get_size() - 1, 2) && (no_more_moves != 2)) {
        return false;
    }
    return true;
}

GameFlow::~GameFlow() {
    delete playing_board;
}
