/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#include <limits>
#include "Menu.h"

Menu::Menu(): ai(1), console(2), remote(3){}

int Menu::choosePlayer() {
    int chose = 1; // defult chose.
    bool validInput = false;

    cout << endl << "Welcome to REVERSI!" << endl << endl<< "Please select the player you want to play with:" << endl
         << "AI opponent: 1" << endl << "Console opponent: 2" << endl << "Remote opponent: 3" << endl;

    while(!validInput) {
        cin >> chose;
        if ((chose == ai) || (chose == console) || (chose == remote)) {
            validInput = true;
            cout << endl << "Here we go!!!!" << endl << endl;
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Your input is not valid, please select again." << endl;
        }
    }
    return chose;
}