/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */


#include "BoardLogic.h"
#include "PlayerType.h"
#include "PlayerHuman.h"
#include "PlayerAI.h"
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
    explicit GameFlow(const int &n, const int &selected);

    /**
     * Initializes the board.
     */
    void init_game();

    /**
     * manages a game after the players and board are created.
     */
    void play();

    /**
     * A function that prints a winning message according to the game's results.
     */
    void winMassege();

    /**
     * A function that switches the turns.
     * @param no_moves accepts true if the player does not have any moves to make or false if he does,
     * according to this param it prints (or doesnt) a message.
     */
    void switchTurn(bool no_moves);

    /**
     *
     * @return true if the conditions for the game's end are met or false if not.
     */
    bool isGameOver();
    /**
     * @return the game's boardlogic object.
     */
    BoardLogic* getBoardLogic();

    /**
     * @return the no_more_moves member.
     */
    int getNoMoreMoves();

    /**
     * @return the turn member.
     */
    DiscSymbol getTurn();

    /**
     * GameFlow object destructor.
     */
    ~GameFlow();

private:
    int selected; // Type of game (console, AI or remote).
    PlayerType* black; // The black player (with symbol X).
    PlayerType* white; // The white player (with symbol O).
    DiscSymbol turn; // Which player does the turn belong to.
    int no_more_moves; // counts the number of turns switched in a row (with no move made).
    BoardLogic* boardlogic; //the board logic of the game.
};


#endif //REVERSI_GAMEFLOW_H
