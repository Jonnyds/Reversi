/*
 * name: Jonathan Schwarz
 * ID: 203672910
 */
#include "Board.h"
#include "Player.h"
#include <iostream>
using namespace std;

#ifndef REVERSI_BOARDLOGIC_H
#define REVERSI_BOARDLOGIC_H

/**
 * This object is responsible for updating the possibilities for moves, preforming the moves
 * themselves and updating the player's discs lists - all of which are done every turn.
 */
class BoardLogic {

public:

/**
 * BoardLogic object constructor.
 * @param game_board the game's board object
 * @param player the player which the turn belongs to.
 * @param opponent the opponent of the player currently in turn.
 * @param turn who does tht turn belong to.
 */
    BoardLogic(Board *game_board,Player &player,Player &opponent);

    /**
     * Checks the coordinates of the moves the current player (in turn) can make.
     * @return a vector of coordinates with all the valid moves the player can make.
     */
    vector<coordinates> valid_moves();

    /**
     * Checks for moves in a specific direction from a player's disc on board.
     * @param i defines the direction which the coordinates advance in.
     * @param j the row index of the disc we are currently checking its surrounding
     * (changes within the funcation).
     * @param k the column index of the disc we are currently checking its surrounding
     * (changes within the funcation).
     */
    void check_direction(const int &i, int &j, int &k);

    /**
     * Perform the changes needed on board after adding a new disc to it.
     * @param i defines the direction which the coordinates advance in.
     * @param j the row index of the new disc added by the player (changes within the funcation).
     * @param k the column index of the new disc added by the player (changes within the funcation).
     */
    void flipping(int j, int k);

    /**
     * Changes the discs which need to be flipped to the current player's turn symbol.
     * updating the board and player's lists
     * @param i the row index of the disc we would like to change.
     * @param j the column index of the disc we would like to change.
     */
    void add_to_board(int i, int j);

    /**
     * Checks if the indexes i of j stepped out the the board's bounds.
     * @param i the row index needed to be checked.
     * @param j the column index needed to be checked.
     * @return if the indexes stepped out of the board's bounds.
     */
    bool is_board_end(int i, int j);

    /**
     * Checks if the cell in board with the i and j indexes is empty.
     * @param i the row index.
     * @param j the column index.
     * @return if the cell is empty (had an empty disc).
     */
    bool is_empty(int i, int j);

    /**
     * Checks if the cell in board with the i and j indexes belongs to the opponent.
     * @param i the row index.
     * @param j the column index.
     * @return if the cell belongs to the opponents.
     */
    bool is_opponent(int i, int j);

    /**
     * Prints the valid moves vector.
     */
    void print_vec();

    /**
     * Checks and deletes double appearance of coordinates of valid moves vector.
     */
    void check_double();



private:
    Board* board; // the game board's object
    Player &player_turn; // The player that the turn belongs to.
    Player &player_opponent; // the opponent.
    vector<coordinates> velid_points; // the vector holding the coordinates of the valid moves the player can make.
};


#endif //REVERSI_BOARDLOGIC_H
