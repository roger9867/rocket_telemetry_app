//
// Created by roger on 10/24/25.
//
#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <string>
#include <functional>

namespace httplib {
    struct Response;
    struct Request;
}

typedef httplib::Request Request;
typedef httplib::Response Response;

class CommandHandler {
public:
    virtual void execute(const Request& request, Response& response) = 0;
    virtual std::string endpoint() = 0;

    // Pass by reference to match CPP
    std::function<void(const Request&, Response&)> get_function();
};

#endif //COMMAND_HANDLER_H
