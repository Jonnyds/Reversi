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



    virtual coordinates makeMove(BoardLogic *bl) const;

    /**
     * A virtual function that clones the Player object.
     * @return a clone of the PlayerHuman object.
     */
    virtual PlayerHuman* clone() const;

};


#endif //REVERSI_PLAYER_H
