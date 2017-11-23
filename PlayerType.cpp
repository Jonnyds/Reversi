//
// Created by sahar on 11/23/17.
//

#include "PlayerType.h"
#include<iostream>
using namespace std;

PlayerType::PlayerType(const DiscSymbol sym): PlayerType(sym){

}

void PlayerType::add_disc(const Disc &d) {
    dlist.push_back(d);
    counter++;
}

void PlayerType::remove_disc(const Disc &d) {

    for (int i = 0; i < counter; ++i) {
        if (dlist[i].check_coordinates(d)) {
            dlist.erase(dlist.begin()+ i);
            counter--;
        }
    }
}

vector<Disc> PlayerType::get_disc_list(){
    return dlist;
}


DiscSymbol PlayerType::get_symbol(){
    return symbol;
}

PlayerType::PlayerType() {};