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

    explicit PlayerType (DiscSymbol sym);

    PlayerType();

    void add_disc(const Disc &d);
    void remove_disc(const Disc &d);
    vector <Disc> get_disc_list() const;
    DiscSymbol get_symbol() const;
    virtual coordinates makeMove(BoardLogic *bl) const = 0;

protected:
    DiscSymbol symbol; //The player's symbol.
    vector<Disc> dlist; //The player's disc list.
    int counter; //The number of discs the player has of board.
};

#endif //REVERSI_PLAYERTYPE_H