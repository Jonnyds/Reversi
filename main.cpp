/*
 * name: Jonathan Schwarz
 * ID: 203672910
 */
#include <vector>
#include "GameFlow.h"


using namespace std;

const int n = 8; // n - board's size.
/**
 * @return 0;
 */
int main() {
    GameFlow g(n);
    g.init_game();
    g.play();
    return 0;
}

