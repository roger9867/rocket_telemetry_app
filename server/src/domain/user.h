//
// Created by roger on 10/24/25.
//

#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include <memory>
#include "client.h"

class User {
public:
    std::string name;
    std::string email;
    std::string user_id;
    std::string password_hash;

    std::vector<std::unique_ptr<Client>> clients;

    User() = default;

};

#endif //USER_H
