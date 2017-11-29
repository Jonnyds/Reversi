/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#include <vector>
#include "Disc.h"
#include "PlayerType.h"

using namespace std;

#ifndef REVERSI_PLAYER_H
#define REVERSI_PLAYER_H

/**
 * This object inherits from PlayerType (an abstract class) and iד responsible for managing the human player's
 * members and implementation of PlayerType.
 */
class PlayerHuman: public PlayerType {

public:

    /**
     * A human player's constructor.
     * @param sym the player's symbol.
     */
    explicit PlayerHuman(DiscSymbol sym);

    /**
     * A default human player's constructor.
     */
    PlayerHuman();


    /**
     * Adds a disc to a player's list.
     * @param d the disc we want to add to the player's list.
     */
    void  add_disc       (const Disc &d);

    /**
     * Deletes a disc to a player's list.
     * @param d the disc we want to delete from the player's list.
     */
    void  remove_disc    (const Disc &d);

    /**
     * @return the player's disc list.
     */
    vector<Disc>  get_disc_list  () const;

    /**
     * @return The player's symbol.
     */
    DiscSymbol get_symbol() const;

    /**
     * A virtual function that makes returns the move a player would like to make (AI or console)
     * @param bl the current game's BoardLogic object.
     * @return the move a player decided on.
     */
    virtual coordinates makeMove(BoardLogic *bl) const;

    /**
     * A virtual function that clones the Player object.
     * @return a clone of the PlayerHuman object.
     */
    virtual PlayerHuman* clone() const;

};


#endif //REVERSI_PLAYER_H
