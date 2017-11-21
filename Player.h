/*
 * name: Jonathan Schwarz
 * ID: 203672910
 */

#include <vector>
#include "Disc.h"
#include "PlayerType.h"
using namespace std;

#ifndef REVERSI_PLAYER_H
#define REVERSI_PLAYER_H

/**
 * This object inherits from PlayerType (an abstract class) and in responsible for managing the human player's
 * members and implementation of PlayerType.
 */
class Player: public PlayerType {

public:

    /**
     * A human player's constructor.
     * @param sym the player's symbol.
     */
    explicit Player(DiscSymbol sym);

    /**
     * A default human player's constructor.
     */
    Player();

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
    vector<Disc>  get_disc_list  ();

    /**
     * @return The player's symbol.
     */
    DiscSymbol get_symbol();

};


#endif //REVERSI_PLAYER_H
