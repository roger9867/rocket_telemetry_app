//
// Created by roger on 10/24/25.
//

#ifndef CLIENT_H
#define CLIENT_H

#include <string>


class Client {
    std::string client_id;
    std::string device_token;
    std::string device_platform;

    Client(std::string token);
};



#endif //CLIENT_H
