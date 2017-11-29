/*
 * name: Jonathan Schwarz
 * ID: 203672910
 */

#include "PlayerType.h"

#include <iostream>
using namespace std;

#ifndef BOARD_BOARD_H
#define BOARD_BOARD_H
/**
 * This object holds the game board and its size, it also manages the board
 * adding objects, deleting them and printing the board.
 */
class Board {

public:
    /**
     * Board object constructor.
     * creates the board by adding a second dimantion to an array of pointers creating the
     * board dynamically according to the size requested.
     * @param n holds the size of the board.
     *
     */
    explicit Board(const int &n);


    /**
     * Default Board object constructor.
     */
    Board();

    /**
    * Initializes the board with the first 4 disc objects in the middle of the matrix (the board).
    * @param white recieves the white player signed 'O'.
    * @param black recieves the black player signed 'X'.
    */
    void init(PlayerType *white, PlayerType *black);

    /**
     * Adds a disc object to the board.
     * @param d the disc we would like to add to the board.
     * @param i the row index on the matrix we would like to add the disc to.
     * @param j the column index on the matrix we would like to add the disc to.
     */
    void add_to_board(const Disc &d ,const int &i, const int &j);

    /**
     * @return the size of the matrix.
     */
    int get_size() const;

    /**
     * @return returns the game board.
     */
    Disc** get_board() const;

    /**
     * Prints the game board.
     */
    void print();

    void copy_board(Board* copyboard);

    /**
     * Board object destructor, releasing the dynamically allocated space of the Disc** member.
     */
    ~Board();

private:
    Disc** board; // A double pointer variable used to create a matrix (board) in the constructor.
    int size; // The size of the board matrix height and width.

};


#endif //BOARD_BOARD_H