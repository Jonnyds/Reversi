/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#include "PlayerType.h"
#include "BoardLogic.h"
#ifndef EX2_PLAYERAI_H
#define EX2_PLAYERAI_H



/**
 * This object inherits from PlayerType (an abstract class) and iד responsible for managing the AI player's
 * members and implementation of PlayerType.
 */

class PlayerAI: public PlayerType {
public:

    /**
     * A default AI player constructor.
     */
    PlayerAI();

    /**
     * A virtual function that makes a deep copy of the BoardLogic object and its members.
     * @param bl the current game's BoardLogic object.
     * @return the new BoardLogic object.
     */
    BoardLogic* createDeepCopyOfLogic(BoardLogic* copybl) const;


    /**
     * A virtual function that makes returns the move a player would like to make (AI, console or remote)
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
