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
 * A class which holds abstract functions to all types of players.
 */
class PlayerType {

public:

    /**
     * Playertype constructor.
     * @param sym the player's symbol.
     */
    explicit PlayerType (DiscSymbol sym);

    /**
     * a default constructor for the playertype object.
     */
    PlayerType();

    /**
     * Adds a disc to a player's list.
     * @param d the disc we want to add to the player's list.
     */
    void add_disc(const Disc &d);

    /**
     * Deletes a disc to a player's list.
     * @param d the disc we want to delete from the player's list.
     */
    void remove_disc(const Disc &d);

    /**
     * @return the player's disc list.
     */
    vector <Disc> get_disc_list() const;

    /**
     * @return The player's symbol.
     */
    DiscSymbol get_symbol() const;

    /**
     * copies a player's disc vector.
     * @param copyVec the vector we would like to copy from.
     */
    void copyVector(vector<Disc> copyVec) ;

    /**
     * A virtual function that makes returns the move a player would like to make (AI or console)
     * @param bl the current game's BoardLogic object.
     * @return the move a player decided on.
     */
    virtual coordinates makeMove(BoardLogic *bl) const = 0;

    /**
     * A virtual function that clones the Player object.
     * @return a clone of the Player object.
     */
    virtual PlayerType* clone() const = 0;

protected:
    DiscSymbol symbol; //The player's symbol.
    vector<Disc> dlist; //The player's disc list.
    int counter; //The number of discs the player has of board.
};

#endif //REVERSI_PLAYERTYPE_H