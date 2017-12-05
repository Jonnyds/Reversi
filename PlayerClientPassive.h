//
// Created by jonathan on 05/12/17.
//

#ifndef ROOT_PLAYERCLIENTPASSIVE_H
#define ROOT_PLAYERCLIENTPASSIVE_H

#include "PlayerType.h"

class PlayerClientPassive: public PlayerType {

public:
    PlayerClientPassive(const char *serverIP, int serverPort,DiscSymbol &sym);
    virtual coordinates makeMove(BoardLogic *bl) const;

};


#endif //ROOT_PLAYERCLIENTPASSIVE_H
