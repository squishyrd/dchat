//
// Created by kf on 10/31/25.
//

#include "../include/decoder.h"

/// extracts the userdata from the recived text
/// @param message the raw text
/// @param msg the extracted userdata
void Decoder::formatMessage(std::string message, Message* msg) {

    /*
     * let's assume that the message is like this: (XML)
     * <fromuser>u1</fromuser>
     * <touser>u2</touser>
     * <text>Hello World!</text>
     * <time>123456789</time>
     */

    size_t start, end;

    if ((start = message.find("<fromuser>")) != std::string::npos & (end = message.find("</fromuser>")) != std::string::npos) {
        start += 10;
        msg->fromuser = message.substr(start, end - start);
    }

    if ((start = message.find("<touser>")) != std::string::npos & (end = message.find("</touser>")) != std::string::npos) {
        start += 8;
        msg->touser = message.substr(start, end - start);
    }

    if ((start = message.find("<text>")) != std::string::npos & (end = message.find("</text>")) != std::string::npos) {
        start += 6;
        msg->text = message.substr(start, end - start);
    }

    if ((start = message.find("<time>")) != std::string::npos & (end = message.find("</time>")) != std::string::npos) {
        start += 6;
        msg->time = std::stoll(message.substr(start, end - start));
    }
}
