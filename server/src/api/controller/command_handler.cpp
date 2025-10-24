//
// Created by roger on 10/24/25.
//

#include "json.hpp"
#include "command_handler.h"
#include "connection_handler.h"
#include "httplib.h"
#include "command_handler.h"

using json = nlohmann::json;


    std::function<void(const httplib::Request&, httplib::Response&)> CommandHandler::get_function() {
        auto function = std::bind(&CommandHandler::execute, this, std::placeholders::_1, std::placeholders::_2);
        return function;
    }
