//
// Created by roger on 10/24/25.
//

#ifndef ROCKET_CREATE_COMMAND_H
#define ROCKET_CREATE_COMMAND_H

#include "../command_handler.h"

class Database;

class RocketCreateCommand : public CommandHandler  {
public:
    RocketCreateCommand(Database* database);
    virtual void execute(const httplib::Request& request, httplib::Response& response) override;
    virtual std::string endpoint() override;
protected:
    Database* database;
};



#endif //ROCKET_CREATE_COMMAND_H
