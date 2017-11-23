/*
 * name: Jonathan Schwarz
 * ID: 203672910
 */

#include "Disc.h"
#include <vector>
using namespace std;

#ifndef EX2_PLAYERTYPE_H
#define EX2_PLAYERTYPE_H
/*
 * An abstract class to all types of players.
 */
class PlayerType {

public:

    explicit PlayerType (DiscSymbol sym): counter(0), symbol(sym){
    }

    PlayerType() {};

    void add_disc(const Disc &d);
    void remove_disc(const Disc &d);
    vector <Disc> get_disc_list();
    DiscSymbol get_symbol();
    virtual void makeMove(BoardLogic bl);

protected:
    DiscSymbol symbol; //The player's symbol.
    vector<Disc> dlist; //The player's disc list.
    int counter; //The number of discs the player has of board.
};

#endif //EX2_PLAYERTYPE_H
