/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#include <vector>
#include "GameFlow.h"
#include "Menu.h"


using namespace std;

const int n = 8; // n - board's size.
/**
 * @return 0;
 */
int main() {
    Menu m = Menu();
    GameFlow g(n, m.choosePlayer());
    g.init_game();
    g.play();
    return 0;
}

