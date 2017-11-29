/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#include <iostream>
using namespace std;
#ifndef EX2_MENU_H
#define EX2_MENU_H
 /**
  * a menu object for selecting the game type.
  */
class Menu {

public:
    /**
     * constructor for the menu object.
     */
    Menu();

    /**
     *
     * @return the type of game the player would like to play (AI or console)
     */
    int choosePlayer();
  //  ~Menu();


private:
    int console;
    int ai;
};

#endif //EX2_MENU_H
