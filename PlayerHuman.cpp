/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#include "PlayerHuman.h"
#include "BoardLogic.h"
#include <limits>
using namespace std;

PlayerHuman::PlayerHuman(DiscSymbol sym): PlayerType(sym){}

coordinates PlayerHuman::makeMove(BoardLogic *bl) const {
    bool move_found = false;
    coordinates coor;
    int x = 0, y = 0;
    cout << "possible moves:";
    bl->print_vec();


    while (!move_found) { // This part checks of the input is valid.

        cout << "please enter the coordinates of the move you would like to do:";
        cin >> x;
        cin >> y;

        for (int move = 0; move < bl->getValidMoves().size(); move++) {
            if (x == bl->getValidMoves()[move].x && y ==bl->getValidMoves()[move].y) {
                move_found = true;
                cout << "Your move is (" << x << ',' << y <<')' <<endl << endl;
            }
        }
        if(!move_found) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Your input is not valid \n";
        }
    }

    coor.x = x;
    coor.y = y;
    return coor;

    // adds the chosen location disc to board
}

PlayerHuman* PlayerHuman::clone() const {
    return new PlayerHuman(*this);
}



