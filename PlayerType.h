/*
 * name: Jonathan Schwarz
 * ID: 203672910
 */

class BoardLogic;

#include "Disc.h"
#include <vector>
using namespace std;

#ifndef REVERSI_PLAYERTYPE_H
#define REVERSI_PLAYERTYPE_H
/*
 * An abstract class to all types of players.
 */
class PlayerType {

public:

    explicit PlayerType (DiscSymbol sym): counter(0), symbol(sym){
    }

    PlayerType() {};

    virtual void add_disc(const Disc &d) = 0;
    virtual void remove_disc(const Disc &d) = 0;
    virtual vector <Disc> get_disc_list() = 0;
    virtual DiscSymbol get_symbol() = 0;

protected:
    DiscSymbol symbol; //The player's symbol.
    vector<Disc> dlist; //The player's disc list.
    int counter; //The number of discs the player has of board.
};

#endif //REVERSI_PLAYERTYPE_H