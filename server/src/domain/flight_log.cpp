//
// Created by roger on 10/24/25.
//

#include "flight_log.h"

FlightLog::FlightLog(std::string log_id, Timestamp timestamp, std::shared_ptr<RocketDesign> design)
        :log_id(log_id),
        timestamp(timestamp),
        design(design) {}

FlightLog::FlightLog(std::string log_id)
        :log_id(log_id) {}

