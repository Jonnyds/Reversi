/*
 * name: Jonathan Schwarz
 * ID: 203672910
 */

#include "Player.h"
#include "Board.h"

#ifndef REVERSI_GAMEFLOW_H
#define REVERSI_GAMEFLOW_H
/**
 * This object runs the game - change turns, player's input, and announces winner.
 */
class GameFlow {

public:

    /**
     * The gameflow object constructor.
     * @param n the board's size.
     */
    explicit GameFlow(const int &n);

    /**
     * Initializes the board.
     */
    void init_game();

    /**
     * manages a game after the players and board are created.
     */
    void play();

    /**
     * GameFlow object destructor.
     */
    ~GameFlow();

private:
    Board* playing_board; // The game's board object.
    Player black; // The black player (with symbol X).
    Player white; // The white player (with symbol O).
    DiscSymbol turn; // Which player does the turn belong to.

};


#endif //REVERSI_GAMEFLOW_H
