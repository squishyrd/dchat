//
// Created by kf on 11/1/25.
//
#pragma once
#ifndef DCHAT_USERMANAGER_H
#define DCHAT_USERMANAGER_H

#endif //DCHAT_USERMANAGER_H

#include <fstream>
#include <string>
#include <algorithm>


class UserManager {
public:
    /// checks if a user has visited before
    /// @param username the string to look for
    static bool checkUserExists(const std::string username);
    static void ufileCheck();
};