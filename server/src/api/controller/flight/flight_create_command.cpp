//
// Created by roger on 10/24/25.
//

#include "flight_create_command.h"
#include <iostream>
#include "httplib.h"
#include <string>

/*
#include "json.hpp"
#include "../../../infrastructure/flight_repository.h"
#include "../../dto/json_serializable.h"
//#include "storage/database.h"

using Json = nlohmann::json;

FlightCreateCommand::FlightCreateCommand(Database* database)
    : database(database) {}

void FlightCreateCommand::execute(const httplib::Request& request, httplib::Response& response) {

    auto json = Json::parse(request.body);

    auto flight_repository = new FlightRepository(  // flight_dto // database, 0);
    flight_dto->from_json(json);

    try {
        flight_repository->create_on_database();
    }
    catch (std::exception& e) {
        response.set_content(Json("unable to create flight"), "text/plain");
        response.status = httplib::StatusCode::BadRequest_400;
        return;
    }

    response.set_content(Json({"id", flight_repository->get_id() } ).dump(), "text/plain");
    response.status = httplib::StatusCode::OK_200;
    std::cout << "flight created successfully" << std::endl;
}

std::string FlightCreateCommand::endpoint() {
    return "/api/flight/create";
}
*/
