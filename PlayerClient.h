//
// Created by sahar on 12/4/17.
//

#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H


#include <string>
#include "PlayerHuman.h"
const int length = 50;

/**
 * This object inherits from PlayerType (an abstract class) and iד responsible for managing the AI player's
 * members and implementation of PlayerType.
 */
class PlayerClient: public PlayerHuman {

//#ifndef REVERSI_CLIENT_H
//#define REVERSI_CLIENT_H

    public:

    /**
     * The player clients constructor
     * @param serverIP the server's IP
     * @param serverPort the server's port
     * @param sym the player's symbol
     */
        PlayerClient(const char *serverIP, int serverPort, DiscSymbol sym);

    /**
     * creating the socket and connecting to the server.
     */
        void connectToServer();

    /**
     * @return the playerClient's socket
     */
        int getClientSocket();

    /**
     * setting the socket member of the playerClient
     * @param socket - the socket to be set
     */
        void setClientSocket(int socket);
    /**
     * @return the player's number
     */
        int getPlayerNum();

    /**
     * set the player's number
     * @param num the player' number
     */
        void setPlayerNum(int num);
    /*
     * receives, checks and asks the server for pre game commands given by the player (such as start, join
     * and asking for a list of games with one player)
     */
        void writeCommande();

    /**
     * A virtual function that returns the move a player would like to make (AI, console or remote)
     * @param bl the current game's BoardLogic object.
     * @return the move a player decided on.
     */
        virtual coordinates makeMove(BoardLogic *bl) const;
/**
 * Converts a char to string
 * @param some a char array
 * @return a string with the content of the char array.
 */
    string convertCharToString (char some[length]);

    private:
        const char *serverIP;
        int serverPort;
        int clientSocket;
        int playernumber;

};


#endif //ROOT_PLAYERCLIENT_H
