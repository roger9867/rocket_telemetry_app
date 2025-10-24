//
// Created by roger on 10/24/25.
//

#ifndef ROCKET_DESIGN_H
#define ROCKET_DESIGN_H
#include <memory>
#include <string>
#include <vector>

class FlightLog;
class Flight;

class RocketDesign {
public:
    std::string id;
    std::string design_name;
    std::string description;

    std::vector<std::shared_ptr<FlightLog>> flights = std::vector<std::shared_ptr<FlightLog>>();

    RocketDesign() = default;
    RocketDesign(std::string id, std::string design_name, std::string description);

};



#endif //ROCKET_DESIGN_H
