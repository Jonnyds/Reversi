//
// Created by jonathan on 23/11/17.
//

#include "PlayerType.h"

PlayerType::PlayerType (DiscSymbol sym): counter(0), symbol(sym){
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

vector<Disc> PlayerType::get_disc_list() const {
    return dlist;
}


DiscSymbol PlayerType::get_symbol() const {
    return symbol;
}

PlayerType::PlayerType() {

}

void PlayerType::copyVector(vector<Disc> copyVec)  {
Disc d;
    for (int i = 0; i < copyVec.size() ; ++i) {
        d = Disc(copyVec[i].get_sym(),copyVec[i].getloc_x(),copyVec[i].getloc_y());
        dlist[i] = d;
    }
}

//virtual void PlayerType::makeMove(BoardLogic &bl) const;



