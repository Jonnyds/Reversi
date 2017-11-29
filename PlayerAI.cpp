/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#include "PlayerAI.h"
#include "PlayerHuman.h"

PlayerAI::PlayerAI() {
    symbol = O;
}
/*
PlayerAI::PlayerAI(PlayerAI &copyAI) {
    PlayerAI copyPlayer = PlayerAI();
    counter = copyAI.get_disc_list().size();

    Disc d;
    for (int i = 0; i < copyAI.get_disc_list().size(); i++) {
        Disc copyDisc = copyAI.get_disc_list()[i];
        d = Disc(copyDisc.get_sym(), copyDisc.getloc_x(), copyDisc.getloc_y());
        copyPlayer.add_disc(d);
    }
}
*/
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
    BoardLogic* virtualBoardLog = createDeepCopyOfLogic(bl);




// a for AI, h for human

    for (int a = 0; a < bl->getValidMoves().size() ; ++a) {

        BoardLogic* bl1 = createDeepCopyOfLogic(virtualBoardLog);
        bl1->valid_moves();
        choseAI.x = bl1->getValidMoves()[a].x;
        choseAI.y = bl1->getValidMoves()[a].y;

        dForAI = Disc(bl1->getPlayerTurn()->get_symbol(), choseAI.x, choseAI.y);
        bl1->getBoard()->add_to_board(dForAI, choseAI.x, choseAI.y);
        bl1->getPlayerTurn()->add_disc(dForAI);
        bl1->flipping(choseAI.x, choseAI.y);

        BoardLogic *bl2 = createDeepCopyOfLogic(bl1);
        bl2->swapPlayers();
        bl2->valid_moves();


        for (int h = 0; h < bl2->getValidMoves().size() ; ++h) {

            BoardLogic* bl3 = createDeepCopyOfLogic(bl2);
            bl3->valid_moves();

            int numFlipping = 0;
            int numOfH = 0;
            int numOfAI = 0;

            choseH.x = bl3->getValidMoves()[h].x;
            choseH.y = bl3->getValidMoves()[h].y;
            dForH = Disc(bl3->getPlayerTurn()->get_symbol(), choseH.x, choseH.y);
            bl3->getBoard()->add_to_board(dForH, choseH.x, choseH.y);
            bl3->getPlayerTurn()->add_disc(dForH);
            bl3->flipping(choseH.x, choseH.y);

            numOfH = bl3->getPlayerTurn()->get_disc_list().size();
            numOfAI = bl3->getPlayerOpponent()->get_disc_list().size();
            numFlipping = numOfH - numOfAI;

            if (numFlipping >= maxConsoleFlipping) {
                maxConsoleFlipping = numFlipping;
            }

            delete bl3;
        }
        if (minFlipping == 0){
            minFlipping = maxConsoleFlipping;
        }
        if (maxConsoleFlipping <= minFlipping) {
            minFlipping = maxConsoleFlipping;
            bestChose.x = choseAI.x;
            bestChose.y = choseAI.y;
        }

        delete bl2;
        delete bl1;
    }
    delete virtualBoardLog;
cout << "O played (" << bestChose.x << "," << bestChose.y << ")" << endl;
    return bestChose;

}

PlayerAI *PlayerAI::clone() const {
    return new PlayerAI(*this);
}

BoardLogic *PlayerAI::createDeepCopyOfLogic(BoardLogic *copybl) const{

    Board* copyboard = new Board(copybl->getBoard()->get_size() - 1);
    copyboard->copy_board(copybl->getBoard());

    PlayerType* copyplayerhuman = copybl->getPlayerOpponent()->clone();
    copyplayerhuman->copyVector(copybl->getPlayerOpponent()->get_disc_list());

    PlayerType* copyplayerAI = copybl->getPlayerTurn()->clone();
    copyplayerAI->copyVector(copybl->getPlayerTurn()->get_disc_list());

    BoardLogic* virtualBoardLog = new BoardLogic(copyboard,copyplayerAI,copyplayerhuman);
   return virtualBoardLog;
}


