//
// Created by sahar on 11/26/17.
//
#include "PlayerType.h"
#ifndef EX2_PLAYERAI_H
#define EX2_PLAYERAI_H




class PlayerAI: public PlayerType {
public:

    /**
     * A human player's constructor.
     * @param sym the player's symbol.
     */

    /**
     * A default human player's constructor.
     */
    PlayerAI();

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

    virtual coordinates makeMove(BoardLogic *bl) const;

};




#endif //EX2_PLAYERAI_H
