//
// Created by sahar on 12/4/17.
//

#include "PlayerClient.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

PlayerClient::PlayerClient(const char *serverIP, int serverPort ,DiscSymbol sym): serverIP(serverIP)
        , serverPort(serverPort), clientSocket(0) ,PlayerHuman(sym){

}

void PlayerClient::connectToServer() {
    int n;
// Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }

// Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }

// Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof address, AF_INET);
    if(server == NULL) {
        throw "Host is unreachable";
    }

// Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char*)&address,sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char*)&serverAddress.sin_addr.s_addr, (char*)server->h_addr, server->h_length);

//htonsconverts values between host and network byte orders
    serverAddress.sin_port = htons(serverPort);

// Establish a connection with the TCP server
    if(connect(clientSocket, (struct sockaddr*)&serverAddress,sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }

    writeCommande();

    n = read(clientSocket, &playernumber, sizeof(playernumber));
    if (n == -1) {
        throw "Error reading from socket";
    }
    cout<<"Connected to server"<<endl<<endl;
    cout <<"you are player number: " << playernumber << " your symbol is: "<< (char) symbol  << endl;
}

coordinates PlayerClient::makeMove(BoardLogic *bl) const {

    coordinates coor;
    int n, i, j;

    if((symbol == X && playernumber == 1) || (symbol == O && playernumber == 2)) {
      coor =  PlayerHuman::makeMove(bl);
        i = coor.x;
        n = write(clientSocket, &i, sizeof(i));
        if (n == -1) {
            throw "Error writing to socket";
        }
        j = coor.y;
        n = write(clientSocket, &j, sizeof(j));
        if (n == -1) {
            throw "Error writing result from socket";
        }
        return coor;

    } else {

        cout << "waiting for the other player's move:" << endl;
        n = read(clientSocket, &i, sizeof(i));
        if (n == -1) {
            throw "Error reading result from socket";
        }

        n = read(clientSocket, &j, sizeof(j));
        if (n == -1) {
            throw "Error reading result from socket";
        }

        cout << "Your opponent's move is (" << i << ',' << j <<')' <<endl << endl;
        coor.x = i;
        coor.y = j;
        return coor;

    }
}


void PlayerClient::setClientSocket(int socket) {
    clientSocket = socket;
}

int PlayerClient::getClientSocket() {
    return clientSocket;
}

int PlayerClient::getPlayerNum() {
    return playernumber;
}

void PlayerClient::setPlayerNum(int num) {
    playernumber = num;
}

void PlayerClient::writeCommande() {

    string scmd;
    string list;
    int n;
    string requestList = "list-games";
    bool validName = false;
    while(true) {
        char name[length];



        cout << "Please enter a command" << endl;

        string command;
        string commandName;
        cin >> command;
        if (command.compare("list-games") != 0 ) {
            cin >> commandName;
            scmd.append(command);
            scmd.append(" ");
            scmd.append(commandName);
        }


        // start command:
        if (command.compare("start") == 0) {
            validName = true;
            n = write(clientSocket, scmd.c_str(), scmd.length());
            if (n == -1) {
                throw "Error writing to socket";
            }
            if (n == 0) {
                throw "Server disconnected";
            }

            break;
        }

        // join command:
        if (command.compare("join") == 0) {
            validName = true;
            n = write(clientSocket, requestList.c_str(), requestList.length());
            if (n == -1) {
                throw "Error writing to socket";
            }
            if (n == 0) {
                throw "Server disconnected";
            }


            int len;
            n = read(clientSocket, &len, sizeof(len));
            if (n == -1) {
                throw "Error reading from socket";
            }
            if (n == 0) {
                throw "Server disconnected";
            }

            for (int i = 0; i < len; ++i) {

                n = read(clientSocket, name, strlen(name));
                if (n == -1) {
                    throw "Error reading from socket2";
                }
                if (n == 0) {
                    throw "Server disconnected2";
                }
                list = convertCharToString(name);

                if (list.compare(commandName) == 0) {
                    n = write(clientSocket, scmd.c_str(), scmd.length());
                    if (n == -1) {
                        throw "Error writing to socket";
                    }
                    if (n == 0) {
                        throw "Server disconnected";
                    }
                } else {
                    cout << "Please enter a valid name" << endl;
                }

            }
            memset(name, 0, sizeof(name));
            break;
        }

        // list-games command:
        if (command.compare("list-games") == 0) {
            validName = true;
            n = write(clientSocket, command.c_str(), command.length());
            if (n == -1) {
                throw "Error writing to socket";
            }
            if (n == 0) {
                throw "Server disconnected";
            }

            int len;
            n = read(clientSocket, &len, sizeof(len));
            if (n == -1) {
                throw "Error writing to socket";
            }
            if (n == 0) {
                throw "Server disconnected";
            }
            cout << endl << "List of games with one player:" << endl;
        for (int i = 0; i < len; ++i) {
            n = read(clientSocket, &name, strlen(name));
            list = convertCharToString(name);
            cout  << endl << i + 1 << ". " << list << endl;

        }
        }
        if (!validName) {
            cout << "Please enter a valid command" << endl;
        }
        command.clear();
        commandName.clear();
        validName = false;
    }
}

string PlayerClient::convertCharToString(char some[length]) {

    /*string str;
    for (int i = 0; i < strlen(some); i++) {
        str.append(1u ,some[i]);
    }*/
    string temp(some);
    string str;
    str.append(temp);

    return str;
}

