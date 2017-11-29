/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#include "Disc.h"

Disc::Disc(const DiscSymbol &sym,const int &x, const int &y): symbol(sym) {
    coordinates_on_board.x = x;
    coordinates_on_board.y = y;
}
Disc::Disc(const DiscSymbol & sym): symbol(sym) {
}

int Disc::getloc_x() const {
    return coordinates_on_board.x;
}

int Disc::getloc_y() const {
    return coordinates_on_board.y;
}

DiscSymbol Disc::get_sym() const {
    return symbol;
}


Disc::Disc() {};
