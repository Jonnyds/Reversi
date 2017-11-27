//
// Created by jonathan on 23/11/17.
//

#include "PlayerType.h"

PlayerType::PlayerType (DiscSymbol sym): counter(0), symbol(sym){
}

PlayerType::PlayerType(const PlayerType &copyCons) {

    PlayerType copyPlayer = PlayerType(copyCons.get_symbol());
    counter = copyCons.get_disc_list().size();

    Disc d;
    for (int i = 0; i < copyCons.get_disc_list().size(); i++) {
       Disc copyDisc = copyCons.get_disc_list()[i];
        d = Disc(copyDisc.get_sym(), copyDisc.getloc_x(), copyDisc.getloc_y());
        copyPlayer.add_disc(d);
    }

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

//virtual void PlayerType::makeMove(BoardLogic &bl) const;



