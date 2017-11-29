//
// Created by sahar on 11/26/17.
//
#include "PlayerType.h"
#include "BoardLogic.h"
#ifndef EX2_PLAYERAI_H
#define EX2_PLAYERAI_H




class PlayerAI: public PlayerType {
public:

    /**
     * AI player constructor.
     * @param sym the player's symbol.
     */

    /**
     * A default AI player constructor.
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
    BoardLogic* createDeepCopyOfLogic(BoardLogic* copybl) const;


    /**
     * A virtual function that makes returns the move a player would like to make (AI or console)
     * @param bl the current game's BoardLogic object.
     * @return the move a player decided on.
     */
    virtual coordinates makeMove(BoardLogic *bl) const;

    /**
     * A virtual function that clones the Player object.
     * @return a clone of the PlayerAI object.
     */
    virtual PlayerAI* clone() const;

};




#endif //EX2_PLAYERAI_H
