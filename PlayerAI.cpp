//
// Created by sahar on 11/26/17.
//

#include "PlayerAI.h"

PlayerAI::PlayerAI() {
    symbol = O;
}

void PlayerAI::add_disc(const Disc &d) {
    PlayerType::add_disc(d);
}

void PlayerAI::remove_disc(const Disc &d) {
    PlayerType::remove_disc(d);
}

vector<Disc> PlayerAI::get_disc_list() {
    return PlayerType::get_disc_list();
}

DiscSymbol PlayerAI::get_symbol() {
    return PlayerType::get_symbol();
}

coordinates PlayerAI::makeMove(BoardLogic *bl) const {

    vector<coordinates> possible_moves;

    possible_moves = bl->getValidMoves();

    for (int i = 0; i < possible_moves.size() ; ++i) {


    }

}
