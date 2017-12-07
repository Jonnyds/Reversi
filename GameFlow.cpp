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
#include <fstream>

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

            string IP;
            string data;
            int port;
            ifstream inFile;
            inFile.open("/home/jonathan/CLionProjects/Reversi & tests/Reversi/setting.txt");
            if(!inFile.is_open()){
                cout << "no no" << endl;
            }
            inFile >> data;
            cout<<"IP: "<<data<<endl;
            inFile >> port;
            cout<<"port: "<<port<<endl;
            inFile.close();
            const char * serverIP = data.c_str();

            black = new PlayerClient(serverIP, port, X);
            try {
                ((PlayerClient *) black)->connectToServer();
            } catch (const char *msg) {
                cout << "Failed to connect to server. Reason:" << msg << endl;
                exit(-1);
            }
            white = new PlayerClient(serverIP, port, O);
            ((PlayerClient *) white)->setClientSocket(((PlayerClient *) black)->getClientSocket());
            ((PlayerClient *) white)->setPlayerNum(((PlayerClient *) black)->getPlayerNum());
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
    int i, noMoveMSG = 0, n;
    Disc d;
    coordinates chose;
    vector<coordinates> possible_moves;
    cout << "It's the black player's turn \n" << endl;

    while (!isGameOver()) {

        boardlogic->getBoard()->print();
        cout << endl << "The white player has: " << white->get_disc_list().size() << " discs on board" << endl;
        cout << "The black player has: " << black->get_disc_list().size() << " discs on board \n" << endl;

        possible_moves = boardlogic->valid_moves(); // checks the valid moves.

        if (possible_moves.empty()) { // check if both players have no more moves then the game ends.
            if (selected == 3) {
                switch (turn) {

                    case X:
                        i = ((PlayerClient *) black)->getClientSocket();
                       n = write(i, &noMoveMSG, sizeof(noMoveMSG));
                        if (n == -1) {
                            throw "Error writing result from socket";
                        }
                        n = write(i, &noMoveMSG, sizeof(noMoveMSG));
                        if (n == -1) {
                            throw "Error writing result from socket";
                        }
                        break;

                    case O:
                        i = ((PlayerClient *) white)->getClientSocket();
                        n = write(i, &noMoveMSG, sizeof(noMoveMSG));
                        if (n == -1) {
                            throw "Error writing result from socket";
                        }
                        n = write(i, &noMoveMSG, sizeof(noMoveMSG));
                        if (n == -1) {
                            throw "Error writing result from socket";
                        }
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
                    if((chose.x != 0) && (chose.y != 0)) {
                        d = Disc(turn, chose.x, chose.y);
                        boardlogic->getBoard()->add_to_board(d, chose.x, chose.y);
                        black->add_disc(d);
                    }
                    break;
                case O:
                   chose = white->makeMove(boardlogic);
                    if((chose.x != 0) && (chose.y != 0)) {
                        d = Disc(turn, chose.x, chose.y);
                        boardlogic->getBoard()->add_to_board(d, chose.x, chose.y);
                        white->add_disc(d);
                    }
                    break;
                case E:
                    break;
            }
            if((chose.x != 0) && (chose.y != 0)) {
                boardlogic->flipping(chose.x, chose.y); //makes the move (changes discs on board).
            }
            switchTurn(false);
        }

    }

    //win massage.
    winMassege();
}

bool GameFlow::isGameOver() {

    int n , end = -6;
    int total_disc = static_cast<int>(white->get_disc_list().size() + black->get_disc_list().size());
    if (total_disc != pow(boardlogic->getBoard()->get_size() - 1, 2) && (no_more_moves != 2)) {
        return false;
    }
    if(selected == 3) {
        switch (turn) {
            case X:
                n = write(((PlayerClient *) black)->getClientSocket(), &end, sizeof(end));
                if (n == -1) {
                    throw "Error writing result from socket";
                }
                n = write(((PlayerClient *) black)->getClientSocket(), &end, sizeof(end));
                if (n == -1) {
                    throw "Error writing result from socket";
                }
                break;
            case O:
                n = write(((PlayerClient *) white)->getClientSocket(), &end, sizeof(end));
                if (n == -1) {
                    throw "Error writing result from socket";
                }
                n = write(((PlayerClient *) white)->getClientSocket(), &end, sizeof(end));
                if (n == -1) {
                    throw "Error writing result from socket";
                }
                break;
        }
    }
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

