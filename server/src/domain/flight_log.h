//
// Created by roger on 10/24/25.
//

#ifndef FLIGHTLOG_H
#define FLIGHTLOG_H
#include <chrono>
#include "rocket_design.h"

using Timestamp = std::chrono::system_clock::time_point;

class FlightLog {
public:
    std::string log_id;
    Timestamp timestamp;
    std::string video_url;

    std::shared_ptr<RocketDesign> design;

    std::vector<TelemetryPoint> telemetry; // full flight telemetry


    FlightLog() = default;
    FlightLog(std::string log_id);
    FlightLog(std::string log_id, Timestamp timestamp, std::shared_ptr<RocketDesign> design);

};

#endif //FLIGHTLOG_H
