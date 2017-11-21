/*
 * name: Jonathan Schwarz
 * ID: 203672910
 */

#include "Player.h"
#include<iostream>
using namespace std;

Player::Player(const DiscSymbol sym): PlayerType(sym){

}

void Player::add_disc(const Disc &d) {
    dlist.push_back(d);
    counter++;
}

void Player::remove_disc(const Disc &d) {

    for (int i = 0; i < counter; ++i) {
        if (dlist[i].check_coordinates(d)) {
            dlist.erase(dlist.begin()+ i);
            counter--;
        }
    }
}

vector<Disc> Player::get_disc_list(){
    return dlist;
}


DiscSymbol Player::get_symbol(){
    return symbol;
}

Player::Player() {};



