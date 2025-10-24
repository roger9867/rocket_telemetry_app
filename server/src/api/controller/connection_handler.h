//
// Created by roger on 10/24/25.
//

#ifndef NETWORK_HANDLER_H
#define NETWORK_HANDLER_H
#include <functional>
#include <string>
#include <unordered_map>


class CommandHandler;

namespace httplib {
    struct Request;
    struct Response;
    class Server;
}

class ConnectionHandler {
public:

    ConnectionHandler(std::string hostname, int port);
    ~ConnectionHandler();

    void register_get_command(CommandHandler* handler);
    void register_put_command(CommandHandler* handler);
    void register_delete_command(CommandHandler* handler);
    void register_patch_command(CommandHandler* handler);
    void register_post_command(CommandHandler* handler);

    void register_options_handler(std::function<void(const httplib::Request&, httplib::Response&)> handler);
    void listen();

protected:
    std::unordered_map<std::string, CommandHandler*> endpoints;
    httplib::Server* server;
    std::string hostname;
    int port;
};

#endif //NETWORK_HANDLER_H
