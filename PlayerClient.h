//
// Created by sahar on 12/4/17.
//

#ifndef ROOT_PLAYERCLIENT_H
#define ROOT_PLAYERCLIENT_H


class PlayerClient {

//#ifndef REVERSI_CLIENT_H
//#define REVERSI_CLIENT_H



    public:
        PlayerClient(const char *serverIP, int serverPort);
        void connectToServer();
        int sendExercise(int arg1, char op, int arg2);
    private:
        const char *serverIP;
        int serverPort;
        int clientSocket;

};


#endif //ROOT_PLAYERCLIENT_H
