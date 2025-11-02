//
// Created by kf on 11/1/25.
//

#include "../include/usermanager.h"

const std::string USERFILENAME = "userfile";

// bool UserManager::checkUserExists(const std::string username) {
//     /// File that stores userdata; Change this to a DB
//     std::fstream ufile(USERFILENAME, std::ios::binary);
//     if (!ufile.is_open()) {
//         // std::exception e();
//         // throw e;
//     }
//
//     /// File
//     std::string userlist;
//
//     ufile >> userlist;
//     ufile.close();
//
//     if (userlist.find(username) == std::string::npos) {
//         std::fstream ufile(USERFILENAME, std::ios::app);
//         ufile << username << '\n';
//         ufile.close();
//         return false; // TODO: Fix: duplicate users occouring
//     } else {
//         return true;
//     }
// }

bool UserManager::checkUserExists(const std::string username) {
    std::ifstream ufile(USERFILENAME);
    std::string line;

    // Check if user exists
    while (std::getline(ufile, line)) {
        // Trim potential whitespace (e.g. \r from Windows line endings)
        line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
        if (line == username) {
            return true; // Already exists, do nothing
        }
    }
    ufile.close();

    // If not found — append new username
    std::ofstream uafile(USERFILENAME, std::ios::app);
    if (!uafile.is_open()) {
        return false; // Couldn’t open file for writing
    }

    uafile << username << '\n';
    uafile.close();

    return true;
}

void UserManager::ufileCheck() {
    std::fstream file(USERFILENAME, std::ios::in);
    std::string command = "touch " + USERFILENAME;

    if (!file.is_open()) {
        system(command.c_str());
    }
}
