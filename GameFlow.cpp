/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#include "GameFlow.h"
#include "PlayerClient.h"
#include <cmath>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

GameFlow::GameFlow(const int &n,const int &selected): selected(selected) {
    switch (selected) {
        case 1:
            white = new PlayerAI();
            black = new PlayerHuman(X);
            break;
        case 2:
            white = new PlayerHuman(O);
            black = new PlayerHuman(X);
            break;
        case 3:
            black = new PlayerClient("127.0.0.1", 8000, X);
            try {
                ((PlayerClient *) black)->connectToServer();
            } catch (const char *msg) {
                cout << "Failed to connect to server. Reason:" << msg << endl;
                exit(-1);
            }
            white = new PlayerClient("127.0.0.1", 8000, O);
            ((PlayerClient *) black)->setClientSocket(((PlayerClient *) black)->getClientSocket());
            ((PlayerClient *) black)->setPlayerNum(((PlayerClient *) black)->getPlayerNum());
            break;
    }

    boardlogic = new BoardLogic(new Board(n),black,white);
    turn = X;
    no_more_moves = 0;
}

void GameFlow::init_game() {
    boardlogic->getBoard()->init(white,black);
}

void GameFlow::play() {
    int i;
    Disc d;
    coordinates chose;
    coordinates noMoveMSG;
    vector<coordinates> possible_moves;
    cout << "It's the black player's turn \n" << endl;

    while (!isGameOver()) {

        boardlogic->getBoard()->print();
        cout << endl << "The white player has: " << white->get_disc_list().size() << " discs on board" << endl;
        cout << "The black player has: " << black->get_disc_list().size() << " discs on board \n" << endl;

        possible_moves = boardlogic->valid_moves(); // checks the valid moves.

        if (possible_moves.empty()) { // check if both players have no more moves then the game ends.
            if (selected == 3) {
                noMoveMSG.x = 0;
                noMoveMSG.y = 0;
                switch (turn) {

                    case X:
                        i = ((PlayerClient *) black)->getClientSocket();
                        write(i, &noMoveMSG, sizeof(noMoveMSG));
                        break;

                    case O:
                        i = ((PlayerClient *) white)->getClientSocket();
                        write(i, &noMoveMSG, sizeof(noMoveMSG));
                        break;
                }

        }
            no_more_moves++;
            switchTurn(true);

        } else {
            no_more_moves = 0;

            switch (turn) {
                case X:
                  chose = black->makeMove(boardlogic);
                    d = Disc(turn, chose.x, chose.y);
                    boardlogic->getBoard()->add_to_board(d, chose.x, chose.y);
                    black->add_disc(d);
                    break;
                case O:
                   chose = white->makeMove(boardlogic);
                    d = Disc(turn, chose.x, chose.y);
                    boardlogic->getBoard()->add_to_board(d, chose.x, chose.y);
                    white->add_disc(d);
                    break;
                case E:
                    break;
            }

            boardlogic->flipping(chose.x, chose.y); //makes the move (changes discs on board).

            switchTurn(false);
        }

    }

    //win massage.
    winMassege();
}

bool GameFlow::isGameOver() {

    int n;
    int total_disc = static_cast<int>(white->get_disc_list().size() + black->get_disc_list().size());
    if (total_disc != pow(boardlogic->getBoard()->get_size() - 1, 2) && (no_more_moves != 2)) {
        return false;
    }
    n = write(((PlayerClient *) black)->getClientSocket(), &total_disc, sizeof(total_disc));
    return true;
}

void GameFlow::winMassege() {
    if (white->get_disc_list().size() > black->get_disc_list().size()) {
        cout << "The white player is the winner";
    } else {
        if (white->get_disc_list().size() < black->get_disc_list().size()) {
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
            boardlogic->swapPlayers();
            boardlogic->clearVec();
            turn = O;
            cout << "It's the white player's turn \n" << endl;
            break;
        case O:
            boardlogic->swapPlayers();
            boardlogic->clearVec();
            turn = X;
            if(no_moves) {

            }
            cout << "It's the black player's turn \n" << endl;
            break;
        case E:
            break;
    }
}

BoardLogic *GameFlow::getBoardLogic() {
    return boardlogic;
}

DiscSymbol GameFlow::getTurn() {
    return turn;
}

GameFlow::~GameFlow() {
    delete boardlogic;
}

