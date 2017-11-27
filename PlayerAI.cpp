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

    int maxConsoleFlipping = 0;
    int minFlipping = 0;
    Disc dForAI;
    Disc dForH;
    coordinates choseAI;
    coordinates choseH;
    coordinates bestChose;
    BoardLogic virtualBoardLog = BoardLogic(*bl);

// a for AI, h for human
    for (int a = 0; a < virtualBoardLog.getValidMoves().size() ; ++a) {

        BoardLogic bl1 = virtualBoardLog;
        choseAI.x = bl1.getValidMoves()[a].x;
        choseAI.y = bl1.getValidMoves()[a].y;

        dForAI = Disc(bl1.getPlayerTurn()->get_symbol(), choseAI.x, choseAI.y);
        bl1.getBoard()->add_to_board(dForAI, choseAI.x, choseAI.y);
        bl1.getPlayerTurn()->add_disc(dForAI);
        bl1.flipping(choseAI.x, choseAI.y);

        BoardLogic bl2 = BoardLogic(bl1.getBoard(),bl1.getPlayerOpponent(),bl1.getPlayerTurn());

        for (int h = 0; h < bl2.getValidMoves().size() ; ++h) {

            int numFlipping = 0;
            int numOfH = 0;
            int numOfAI = 0;

            choseH.x = bl2.getValidMoves()[a].x;
            choseH.y = bl2.getValidMoves()[a].y;
            dForH = Disc(bl1.getPlayerTurn()->get_symbol(), choseH.x, choseH.y);
            bl2.getBoard()->add_to_board(dForH, choseH.x, choseH.y);
            bl2.getPlayerTurn()->add_disc(dForH);
            bl2.flipping(choseH.x, choseH.y);

            numOfH = bl2.getPlayerTurn()->get_disc_list().size();
            numOfAI = bl2.getPlayerOpponent()->get_disc_list().size();
            numFlipping = numOfH - numOfAI;

            if (numFlipping >= maxConsoleFlipping) {
                maxConsoleFlipping = numFlipping;
            }

        }

        if (maxConsoleFlipping <= minFlipping) {
            minFlipping = maxConsoleFlipping;
            bestChose.x = choseAI.x;
            bestChose.y = choseAI.y;
        }

    }
    return bestChose;

}
