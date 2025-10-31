//
// Created by kf on 10/31/25.
//

#ifndef DCHAT_DECODER_H
#define DCHAT_DECODER_H

#include <ctime>
#include <string>
#include <algorithm>

#endif //DCHAT_DECODER_H
/// Decodes a raw XML message into an object
class Message {
public:
    std::string fromuser;
    std::string touser;
    std::string text;
    time_t time;
};

class User {
public:
    time_t lastJoined;
    std::string uname;
};

class Decoder {
public:
    static void formatMessage(std::string message, Message* msg);
};
