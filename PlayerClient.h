//
// Created by sahar on 12/4/17.
//

#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H


#include "PlayerHuman.h"

class PlayerClient: public PlayerHuman {

//#ifndef REVERSI_CLIENT_H
//#define REVERSI_CLIENT_H

    public:
        PlayerClient(const char *serverIP, int serverPort, DiscSymbol sym);
        void connectToServer();
        int getClientSocket();
        void setClientSocket(int socket);
        virtual coordinates makeMove(BoardLogic *bl) const;

    private:
        const char *serverIP;
        int serverPort;
        int clientSocket;
        int playernumber;

};


#endif //ROOT_PLAYERCLIENT_H
