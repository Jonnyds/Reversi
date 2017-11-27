//
// Created by sahar on 11/26/17.
//

#include "PlayerAI.h"
#include "PlayerHuman.h"

PlayerAI::PlayerAI() {
    symbol = O;
}

PlayerAI::PlayerAI(const PlayerAI &copyAI) {
    PlayerAI copyPlayer = PlayerAI();
    counter = copyAI.get_disc_list().size();

    Disc d;
    for (int i = 0; i < copyAI.get_disc_list().size(); i++) {
        Disc copyDisc = copyAI.get_disc_list()[i];
        d = Disc(copyDisc.get_sym(), copyDisc.getloc_x(), copyDisc.getloc_y());
        copyPlayer.add_disc(d);
    }
}

void PlayerAI::add_disc(const Disc &d) {
    PlayerType::add_disc(d);
}

void PlayerAI::remove_disc(const Disc &d) {
    PlayerType::remove_disc(d);
}

vector<Disc> PlayerAI::get_disc_list() const {
    return PlayerType::get_disc_list();
}

DiscSymbol PlayerAI::get_symbol() const {
    return PlayerType::get_symbol();
}

coordinates PlayerAI::makeMove(BoardLogic *bl) const {



// a for AI, h for human
    for (int a = 0; a < possible_moves.size() ; ++a) {

        for (int h = 0; h <  ; ++h) {


        }


    }

}
