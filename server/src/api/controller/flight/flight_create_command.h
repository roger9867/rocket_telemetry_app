//
// Created by roger on 10/24/25.
//

#ifndef FLIGHT_CREATE_COMMAND_H
#define FLIGHT_CREATE_COMMAND_H
#include "../command_handler.h"


class Database;

class FlightCreateCommand: public CommandHandler {
public:
    FlightCreateCommand(Database* database);
    virtual void execute(const httplib::Request& request, httplib::Response& response) override;
    virtual std::string endpoint() override;
protected:
    Database* database;
};

#endif //FLIGHT_CREATE_COMMAND_H
