//
// Created by kf on 10/29/25.
// Basic Code for a chatapp server
//

#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <ctime>
#include "../include/decoder.h"

#define PORT 3412 // make this configurable
#define BUFFERSIZE 2048

using std::cout;
using std::cerr;

int main(int argc, char* argv[]) {
    //if (argc < 2) return 1;

    int srvSock = socket(AF_INET, SOCK_STREAM, 0); // trying to create a socket
    int addrlen = 0;
    if (srvSock < 0) { // checking it for an error
        cerr << "Failed to create socket" << '\n';
        exit(1); // EXIT_FAILURE
    }
    int optval = 1;
    setsockopt(srvSock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));


    sockaddr_in addr; // setting up port options
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_family = AF_INET; // use IPV4
    addr.sin_port = htons(PORT);
    addrlen = sizeof(addr);

    //bind port to the socket
    if (bind(srvSock, (sockaddr* )&addr, sizeof(addr)) < 0) {
        cerr << "Failed to bind socket on to port " << PORT << '\n';
        exit(1); // exit failure
    }

    // listening for a connection
    if (listen(srvSock, 1024) < 0) {
        cerr << "failed to listen\n";
        exit(1);
    }

    cout << "Listening on port " << PORT << "\n";
    int clientSock = 0;

    while (1) { // main loop
        clientSock = accept(srvSock, (sockaddr* )&addr, (socklen_t *)&addrlen);
        char buffer[BUFFERSIZE] = {0}; // auto clear stack var
        if (clientSock < 0) {
            cerr << "accept failed: \n";
            continue; // skip to the next iter
        }
        size_t bytesRead = read(clientSock, buffer, BUFFERSIZE - 1);
        buffer[bytesRead] = '\0'; // null terminate
        Message mg;
        Decoder::formatMessage(buffer, &mg);
        cout << "Contents: " << buffer << '\n';
        cout << "mg.fromuser: " << mg.fromuser << '\n';
        cout << "mg.touser: " << mg.touser << '\n';
        cout << "mg.text: " << mg.text << '\n';
        cout << "mg.time: " << mg.time << '\n';
    }


    return 0x0; // hex, just for fun
}